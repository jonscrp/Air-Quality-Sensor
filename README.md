# Air Quality Sensor 🌱 

 Welcome to our ASRC Citizen Sensors Community! We're still building this space but feel free to use the materials available. Contact [kkrueger@gc.cuny.edu](mailto:kkrueger@gc.cuny.edu) if you have any questions. We'll try to answer as soon as possible!
 
 The Air Quaity Sensor (AQS) is a **low-cost**, **low-power** DIY device with sensors for **CO2**, **temp-pressure-relativehumidity**, and **PM2.5** (dust or smoke). It has an on-board logger and WiFi connectivity to Google Sheets for (almost) real time data reporting. 

<img src="images/air-qaulity-sensor-V2.jpeg" width="200" height = "300"> <img src="images/WIFI LOGGER CSL-AQS-V2.0.png" width="600" height = "300"> 

**Table of Contents:**

   * [Community Sensor Lab - Air Quality Sensor]
      * [Technologies](#technologies-)
         * [Microcontroller Boards](#featherM0-Microcontroller-Boards)
         * [Sensors](#sensors)
         * [Additional Parts](#additional-Parts)
      * [Getting Started with Arduino](#getting-started-)
      * [Downloading Code from Github](#using-github-)
      * [Connecting to WiFi + Google Spreadsheet](#http-request-to-google-spreadsheet-)
       * [Versions ](#versions-)
         * [AQS - v2](#air-quality-sensor-v2)
         * [AQS - v1](#air-quality-sensor-v1)

## Technologies 🖥 
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
|Sensirion SPS380 PM2.5| <img src="images/Sensirion-SPS380-PM2.5.jpg" width="200" height = "200" >|Measures particulate matter PM2.5+|[Digi-Key](https://www.digikey.com/en/products/detail/sensirion-ag/SPS30/9598990)

### Additional-Parts
| Part | Part Image | Use | Purchase Link |
|----------------|-------------------------------|----------|:--------------------------:|
|Battery Lithium Polymer LiPo 3.7V| <img src="images/Battery-Lithium-Polymer-LiPo-3.7V.jpeg" width="200" height = "200"> |Device's battery|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/354/5054541)
|Battery Coin cr1220| <img src="images/Battery-Coin-cr1220.jpeg" width="200" height = "200"> |Clock Battery|[Digi_Key](https://www.digikey.com/en/products/detail/renata-batteries/RENATA-CR1220-TS-1/13283109)
|Micro SD| <img src="images/Micro-SD.jpeg" width="200" height = "200">|non volatile memory|[Digi-Key](https://www.digikey.com/en/products/detail/delkin-devices-inc/USDCOEM-16GB/13882332)
|Jumper Wires| <img src="images/1954-02.jpg" width="200" height = "200">|connecting|[Adafruit](https://www.adafruit.com/product/1954)

## Diagram 📝          
<img src="images/Comm Sensor Lab V2.0 diagram.png"> 

## Getting-Started💡 
For instructions on getting started with Arduino and setting up the necessary libraries and packages for the Air Quality Sensor, take a look at our guide:
[Installing Arduino and Getting Started](https://docs.google.com/document/d/16o8Np3GaZfSjQlxNWIgi12ycb2CosCJ2blwEGiTplbA/edit?usp=sharing)

## Using GitHub 🐈‍⬛🐙  

## HTTP-Request-to-Google-Spreadsheet 🌐
The Air Quality Sensor can post data in real-time to a spreadsheet online through HTTP methods!

For instructions on getting the AQS connected with a Google Spreadsheet, take a look at our guide
[HTTP POSTing to Google Spreadsheet](https://docs.google.com/document/d/1yNolfJr7s9rs_ewV7vN-bUsllEiPPxo2xeQbsmszQKE/edit?usp=sharing)


## Versions 🛠
### Air-Quality-Sensor-v2
This is our latest version of our Air Quality Sensor. The code on this page is the latest code.
### Air-Quality-Sensor-v1
Code from the first version of the Air Quality Sensor can be seen on the branch [Version-1](https://github.com/Community-Sensor-Lab/Air-Quality-Sensor/tree/Version-1)
