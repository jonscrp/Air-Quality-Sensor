/*
   COMMUNITY SENSOR LAB AIR QUALITY SENSOR

   featherM0-Wifi + featherwing adalogger-SD-RTC + SCD30-CO2 + BME280-TPRH + OLED display.

   The SCD30 has a minimum power consumption of 5mA and cannot be stop-started. It's set to 55s (30s nominal)
   sampling period and the featherM0 sleeps for 2 x 16 =32s, wakes and waits for data available.
   Button A toggles display on/off but must be held down for 16s max and then wait 16s to toggle again.

   Logs: date time, co2, t, rh, t2, press, rh2, battery voltage, status

   https://github.com/Community-Sensor-Lab/Air-Quality-Sensor

   RICARDO TOLEDO-CROW NGENS, ESI, ASRC, CUNY,
   AMALIA TORRES, CUNY, SEPTEMBER 2020

*/
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <Adafruit_SleepyDog.h>
#include "RTClib.h"
#include "SparkFun_SCD30_Arduino_Library.h"
#include <Adafruit_GFX.h>

#include <Adafruit_SH110X.h>


#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <WiFi101.h>
#include "arduino_secrets.h" // wifi name and password in .h file. see tab

#define VBATPIN A7 // this is also D9 button A disable pullup to read analog
#define BUTTON_A  9  // Oled button also A7 enable pullup to read button
#define BUTTON_B  6  // oled button
#define BUTTON_C  5  // oled button

char ssid[] = SECRET_SSID;    // your network SSID (name)
char pass[] = SECRET_PASS;    // your network password (use for WPA, or use as key for WEP)
String PostCommand = "POST /macros/s/"+ String(GSSD_ID) + "/exec?value=Hello HTTP/1.1";      // Google Sheets Script Deployment ID

int status = WL_IDLE_STATUS;
char server[] = "script.google.com"; // name address for Google scripts as we are communicationg with the scripg (using DNS)

WiFiSSLClient client; // make SSL client
// these are the commands to be sent to the google script: namely add a row to last in Sheet1 with the values TBD
String payload_base =  "{\"command\":\"appendRow\",\"sheet_name\":\"Sheet1\",\"values\":";
String payload = "";

RTC_PCF8523 rtc; // Real Time Clock for RevB Adafruit logger shield

Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

Adafruit_BME280 bme; // the bme tprh sensor
File logfile;  // the logging file
SCD30 airSensor; // sensirion scd30 ndir

const int SD_CS = 10; // Chip select for SD card default for Adalogger
uint8_t stat = 0; // status byte

void setup(void) {

  pinMode(VBATPIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  delay(5000); Serial.println(__FILE__);

  Serial.println(PostCommand);

  initializeWiFi();
  initializeOLED();
  logfile = initializeSD(SD_CS);
  initializeBME();
  initializeSCD30(55); // this sets CO2 sensor to 1 min intervals (max recommended)

  Wire.begin();  // connect to RTC
  if (!rtc.begin()) {
    Serial.println("RTC failed");
    stat = stat | 0x04; // 3rd bit set 'rtc not started'
    //while (1);
  }
  else
    Serial.println("RTC ok");
  Serial.println();
  // TO SET TIME at compile: run once to syncro then run again with line commented out
  //  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  delay(2000);
  Serial.println("Date______\tTime____\tCO2ppm\tTempC\tRH%\tTempC\tP_mBar\tRH%\tVbatMV\tstatus");
  logfile.println("Date______\tTime____\tCO2ppm\tTempC\tRH%\tTempC\tP_mBar\tRH%\tVbatMV\tstatus");
}

char outstr[100];
int32_t Tsleep = 0;
bool displayState = true;
bool buttonAstate = true;
int lastTimeToggle = 0;
int timeDebounce = 100;

void loop(void)  {

  uint8_t ctr = 0;
  stat = stat & 0xEF; // clear bit 4 for CO2 sensor

  float Tbme = bme.readTemperature();
  float Pbme = bme.readPressure() / 100; // for hPa
  float RHbme = bme.readHumidity();

  airSensor.setAmbientPressure(Pbme); // update CO2 sensor to current pressure
  // wait for data avail on CO2 sensor
  while (!airSensor.dataAvailable()) {
    delay(1000);
    if (ctr > 31) {  // timeout is 31s
      stat = stat | 0x10; // set bit 4 timeout
      break;
    }
    else
      ctr += 1;
  }

  // read from co2 sensor
  uint16_t CO2 = airSensor.getCO2();
  float Tco2 = airSensor.getTemperature();
  float RHco2 = airSensor.getHumidity();

  DateTime now;
  now = rtc.now(); // fetch the date + time

  pinMode(VBATPIN, INPUT); // read battery voltage
  float measuredvbat = analogRead(VBATPIN) * 0.006445;
  pinMode(BUTTON_A, INPUT_PULLUP);

  sprintf(outstr, "%02u/%02u/%02u %02u:%02u:%02u, %.2d, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %x",
          now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second(),
          CO2, Tco2, RHco2, Tbme, Pbme, RHbme, measuredvbat, stat);
  Serial.println("Date Time \tCO2 \tTco2 \tRHco2 \tTbme \tPbme \tRHbme \vbat(mV) \tstatus");
  Serial.println(outstr);
  logfile.println(outstr);
  logfile.flush();   // Write to disk. Uses 2048 bytes of I/O to SD card, power and takes time

  payloadUpload(outstr);
  
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("No WiFi");
  };

  for (int i = 1; i <= 2; i++)  {  // 32s =2x16s sleep
    displayState = toggleButton(BUTTON_A, displayState, buttonAstate, lastTimeToggle, timeDebounce);
    if (displayState)  { // turn display on with data
      display.clearDisplay();

      display.setTextSize(1);
      display.setTextColor(SH110X_WHITE);

      display.setCursor(0, 0);
      display.print("CO2 ppm "); display.print(CO2);
      display.print("  V "); display.println(measuredvbat);
      display.print("T C     "); display.println(Tbme);
      display.print("P mBar  "); display.println(Pbme);
      display.print("RH%     "); display.print(RHbme);
      if (WiFi.status() == WL_CONNECTED) {
        display.println("    w");
      }
      else  {
        display.println(" no w");
      };
      display.display();
    }
    else  {  // turn display off
      display.clearDisplay();
      display.display();
    };

    int sleepMS = Watchdog.sleep();// remove comment after final push
    //    delay(16000); // uncomment to debug because serial communication doesn't come back after sleeping

  }
}
