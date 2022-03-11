# Air Quality Sensor V3 using WiFi to Google Sheets 🌱 

 Welcome to our ASRC Community Sensor Lab! We're still building this space but feel free to use the materials available. Contact [kkrueger@gc.cuny.edu](mailto:kkrueger@gc.cuny.edu) if you have any questions. We'll try to answer as soon as possible!
 
 The Air Quaity Sensor (AQS) is a **low-cost**, **low-power** DIY device with sensors for **CO2**, **temp-pressure-relativehumidity**, and **PM2.5** (dust or smoke). It has an on-board logger and WiFi connectivity to Google Sheets for (almost) real time data reporting. 
<br>

V3 has code for the SPS30 PM2.5 and HSC differential pressure (Met Museum) sensors. If these are not pesent the code keeps going and reports 'no sensor' to SD log and google sheet. Additionally, keeps the start-stop for Wifi and sleeps all for ~25mA operation.

<img src="images/air-qaulity-sensor-V2.jpeg" width="200" height = "300"> <img src="images/WIFI LOGGER CSL-AQS-V2.0.png" width="600" height = "300"> 
<br>
<img src="images/IMG_2107.jpg" width="400" height = "250">                    <img src="images/IMG_2110.JPG" width="400" height = "450">

<br>

## Contents:

   * Community Sensor Lab 🌱 - Air Quality Sensor
      * [Starting From Scratch](#Getting-Started-)
      * [Assembly] (#assembly-)
      * [Arduino IDE] (#arduino-)
      * [Setting Up Google Spreadsheet] (#google spreadsheet-)

## Getting-Started-💡 
* [How to Solder Air Quality Sensor](https://docs.google.com/document/d/1l6jeO-1NOw7vDZXchC9iGBB8vkmnokzwbz_wixmtFyU/edit?usp=sharing)

* [Air Quality Sensor Boards Assembly](https://docs.google.com/document/d/1AezJ0XiPEsc3vEHGtJqxCqGEe5GDv0d0T-DoVZDCgCY/edit?usp=sharing)

* [How to Attach Sensors to Boards](https://docs.google.com/document/d/1BrGlBl2Zau5XgyUAorEzxkr_Fa7h0j_XQgn0lQ-tBvw/edit?usp=sharing)

* [Installing Arduino and Getting Started](https://docs.google.com/document/d/16o8Np3GaZfSjQlxNWIgi12ycb2CosCJ2blwEGiTplbA/edit?usp=sharing)


## Downloading Code 🐈‍⬛  
If you are new to Github, **Welcome!** 
Check out our guide:
[Downloading CSL AQS Code from Github](https://docs.google.com/document/d/1Vb9AufqkUwsVKtdozXMc4aboDjLqBNuyTXmZpECdKx0/edit?usp=sharing)  where we explain how to download the necessary code for the Community Sensor Lab's Air Quality Sensor.

## HTTP-Request-to-Google-Spreadsheet 🌐
The Air Quality Sensor can post data in (almost) real-time to a spreadsheet online through HTTP methods!
For instructions on getting the AQS connected with a Google Spreadsheet, take a look at our guide: [HTTP Posting to Google Spreadsheet](https://docs.google.com/document/d/1yNolfJr7s9rs_ewV7vN-bUsllEiPPxo2xeQbsmszQKE/edit?usp=sharing).
<br>In our guide we provide:
* A template specifically for the Air Quality Sensor 
* Step-by-step instructions to using the Google Script Editor for the AQS and deploying your app script
* Managing troubleshooting issues
* Step-by-step instructions to then connecting your App Script to the AQS through the Arduino IDE

## Parts-List 🖥 
Here are the materials you will need with links of where to find them. 

### FeatherM0-Microcontroller-Boards

| Board | Board Image | Use | Link |
|----------------|-------------------------------|----------|:--------------------------:|
|Feather M0 WiFi (WINC1500))| <img src="images/Feather-M0-WiFi.jpeg" width="200" height = "200" >  |Connects to WiFi network. Brain of the system|[Adafruit](https://www.adafruit.com/product/3010)
|Featherwing Logger (RTC microSD)| <img src="images/Featherwing-Logger.jpeg" width="200" height = "200"> |Slot for microSD. Has a real time clock|[Adafruit](https://www.adafruit.com/product/2922)
|Featherwing OLED  | <img src="images/Featherwing-OLED.jpeg" width="200" height = "200" >|Displays data values and can graph functions|[Adafruit](https://www.adafruit.com/product/2900)
|Feather Terminal Block | <img src="images/Feather-Terminal-Block.jpeg" width="200" height = "200" >|Holds all the components together|[Adafruit](https://www.adafruit.com/product/2926)

### Sensors
| Sensor | Sensor Image | Use | Purchase Link |
|----------------|-------------------------------|----------|:--------------------------:|
|Sensirion SD30 CO2 NDIR| <img src="images/Sensirion_SD30_CO2_NDIR.jpeg" width="200" height = "200" >|Measures CO2 in PPM|[Digi-Key](https://www.digikey.com/en/products/detail/sensirion-ag/SCD30/8445334?s=N4IgTCBcDaIMIHkwAIDKBRAcqhAlZAkmHMgLIIAiAQgKqrIAKA6qSALoC%2bQA)
|BME280 Temp. Press. Rel Humidity| <img src="images/BME280.jpeg" width="200" height = "200"> | Measures temperature C, pressure hPa and relative humidity %|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/2652/5604372)
|Sensirion SPS380 PM2.5| <img src="images/Sensirion-SPS380-PM25.jpg" width="200" height = "200" >|Measures particulate matter PM2.5+|[Digi-Key](https://www.digikey.com/en/products/detail/sensirion-ag/SPS30/9598990)
|Differential Pressure| <img src="images/hsc-differential-pressure.jpeg" width="200" height = "200" >|Measures particulate matter PM2.5+|[No Link Available at this time](https://www.digikey.com/en/products/detail/sensirion-ag/SPS30/9598990)

### Additional-Parts
| Part | Part Image | Use | Purchase Link |
|----------------|-------------------------------|----------|:--------------------------:|
|MiniBoost 5V| <img src="images/miniboost-5v.jpeg" width="200" height = "200"> |Boosts battery pawer to 5V|[Digi-Key](https://www.adafruit.com/product/4654)
|Battery Lithium Polymer LiPo 3.7V| <img src="images/Battery-Lithium-Polymer-LiPo-3.7V.jpeg" width="200" height = "200"> |Device's battery|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/354/5054541)
|Battery Coin cr1220| <img src="images/Battery-Coin-cr1220.jpeg" width="200" height = "200"> |Clock Battery|[Digi_Key](https://www.digikey.com/en/products/detail/renata-batteries/RENATA-CR1220-TS-1/13283109)
|Micro SD| <img src="images/Micro-SD.jpeg" width="200" height = "200">|non volatile memory|[Digi-Key](https://www.digikey.com/en/products/detail/delkin-devices-inc/USDCOEM-16GB/13882332)
|Jumper Wires| <img src="images/1954-02.jpg" width="200" height = "200">|connecting|[Adafruit](https://www.adafruit.com/product/1954)

## Diagram 🔦          
<img src="images/CSL V3.0 diagram 1.png">


## Solar Integration ☀️ 
The Air Quality Sensor can be powered by the sun!
For instructions on getting the AQS connected to a solar panel visit our document guide: [Solar Integration for the AQS](https://docs.google.com/document/d/1Q-aV4gpCV_NFu_VYhCmv1KPlE8r25asAGBMgROmjtNk/edit?usp=sharing).

## Versions 🛠
### Air-Quality-Sensor-V3
This is our latest version of our Air Quality Sensor. The code on this page is the latest code. Bigger display screen, power booster, PM 2.5 and differential pressure sensors are included in this version.
### Air-Quality-Sensor-V2.1
Code from version 2.1 of the Air Quality Sensor can be seen on the branch [Version-2.1](https://github.com/Community-Sensor-Lab/Air-Quality-Sensor/tree/Version-2.1)
### Air-Quality-Sensor-v1
Code from the first version of the Air Quality Sensor can be seen on the branch [Version-1](https://github.com/Community-Sensor-Lab/Air-Quality-Sensor/tree/Version-1)

