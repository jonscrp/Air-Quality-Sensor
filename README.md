# Air Quality Sensor 🌱 

 Welcome to our ASRC Citizen Sensors Community! We're still building this space but feel free to use the materials available. Contact [kkrueger@gc.cuny.edu](mailto:kkrueger@gc.cuny.edu) if you have any questions. We'll try to answer!
 
 The Air Quaity Sensor (AQS) is a low-cost, low-power DIY device with sensors for CO2, temp-pressure-relativehumidity, and PM2.5 (dust or smoke). It has an on-board logger and WiFi connectivity to Google Sheets for (almost) real time data reporting. 

<img src="images/CSL-AQS-Ver2.0.jpeg" width="350" height = "250">     <img src="images/WIFI LOGGER CSL-AQS-V2.0.png" width="600" height = "300"> 

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

|    Boards, Batteries, and Headers  |Image|       Purpose           | Link |
|------------------------|---------------------|-----------------------------|----------------------------|
|Terminal Block (Base)| <img src="https://media.digikey.com/Photos/Adafruit%20Industries%20LLC/2926-Contents.jpg" width="200" height = "200" >  |Used to keep everything together. Sensors are connected here      |[Adafruit](https://www.adafruit.com/product/2926)
|Display Board (OLED)| <img src="https://media.digikey.com/Photos/Adafruit%20Industries%20LLC/MFG_2900.jpg" width="200" height = "200" >    |Displays values for gases or particles and can graph functions|[Adafruit](https://www.adafruit.com/product/2900)
|Battery | <img src="https://media.digikey.com/Photos/Micropower-Battery/MFG_REN-CR1220.IB-BULK.jpg" width="200" height = "200" >|-- is en-dash, --- is em-dash|
|Battery | <img src="https://media.digikey.com/Photos/Adafruit%20Industries%20LLC/MFG_354.jpg" width="200" height = "200" >|-- is en-dash, --- is em-dash|
|Dashes          |`-- is en-dash, --- is em-dash`|-- is en-dash, --- is em-dash|
| --- |---| ---|
| ffsddsf | ffsfsdf |
| ffsddsf | ffsfsdf |
## WiFi🌐          
<img src="images/Comm Sensor Lab V2.0 diagram.png"> 
## Versions 🛠
### Air-Quality-Sensor-v1
Code from the first version of the Air Quality Sensor can be seen on the branch [Version-1](https://github.com/Community-Sensor-Lab/Air-Quality-Sensor/tree/Version-1)
### AQS - v2
This is the repository with the latest code

Feather M0 Microcontroller boards

Feather M0 WiFi (WINC1500)
Featherwing Logger (RTC microSD)
Featherwing OLED 
Feather terminal block

Sensors

Sensirion SD30 CO2 NDIR
BME280 Temp. Press. Rel Humidity 
Sensirion SPS30 PM2.5

Other necessary stuff

Battery Lithium Polymer LiPo 3.7V
Battery coin cr1220
Memory microSD (>8GB)<img width="281" alt="image" src="https://user-images.githubusercontent.com/19189152/114201488-3f038600-9924-11eb-8e6c-756f9b7baf52.png">

