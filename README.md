# Air Quality Sensor 🌱 

 Welcome to our ASRC Citizen Sensors Community! We're still building this space but feel free to use the materials available. Contact [kkrueger@gc.cuny.edu](mailto:kkrueger@gc.cuny.edu) if you have any questions. We'll try to answer!
 
 The Air Quaity Sensor (AQS) is a low-cost, low-power DIY device with sensors for CO2, temp-pressure-relativehumidity, and PM2.5 (dust or smoke). It has an on-board logger and WiFi connectivity to Google Sheets for (almost) real time data reporting. 

<img src="images/air-qaulity-sensor-V2.jpeg" width="200" height = "300">      <img src="images/WIFI LOGGER CSL-AQS-V2.0.png" width="600" height = "300"> 

**Table of Contents:**

   * [Community Sensor Lab - Air Quality Sensor](#floodsense-project-sensor-experiments)
      * [Technologies](#featherM0_Microcontroller_Boards)
         * [Microcontroller boards](#featherM0_Microcontroller_Boards)
         * [Sensors](#sensors)
      * [Data Collection via HTTP](#experiment-reports)
      * [Versions ](#versions-)
        * [AQS - v2](#air-quality-sensor-v2)
        * [AQS - v1](#air-quality-sensor-v1)

## Technologies💡
### FeatherM0_Microcontroller_Boards

| Board | Image | Use | Link |
|---------|---------------|-----------------|-------|
|Feather M0 WiFi (WINC1500))| <img src="images/Feather-M0-WiFi.jpeg" width="200" height = "200" >  |Wifi feather board connects Arduino to a WiFi network. The microcontroller is the brain of the system     |[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/3010/5848448)
|Featherwing Logger (RTC microSD)| <img src="images/Featherwing-Logger.jpeg" width="200" height = "200" >    |You can insert a microSD in the logger. The data that the sensors collect is stored here. The logger also has a real time clock. The clock keeps track of the time and date even when the Arduino is turned off|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/2922/5885911?s=N4IgTCBcDaIIIBE4BkDyBxdBRASgAgDEs4AVACVwHUBJAOXTwFo8cSBhPAajwGUEQAugF8gA)
|Featherwing OLED  | <img src="images/Featherwing-OLED.jpeg" width="200" height = "200" >|Displays values for gases or particles and can graph functions|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/2900/5810890)
|Feather Terminal Block | <img src="images/Feather-Terminal-Block.jpeg" width="200" height = "200" >|The base holds all the components together. Sensors are placed here and all other boards are stacked on top|[Digi-Key](https://www.digikey.com/en/products/detail/adafruit-industries-llc/2926/5959339?s=N4IgTCBcDaIGYFMCGAXAFggTgdwJYDsBzAAhSwFsCkAbYgI2oHsBjAaxAF0BfIA)

### Sensors
## WiFi🌐          
<img src="images/Comm Sensor Lab V2.0 diagram.png"> 
## Versions 🛠
### Air-Quality-Sensor-v1
Code from the first version of the Air Quality Sensor can be seen on the branch [Version-1](https://github.com/Community-Sensor-Lab/Air-Quality-Sensor/tree/Version-1)
### AQS - v2
This is the repository with the latest code
