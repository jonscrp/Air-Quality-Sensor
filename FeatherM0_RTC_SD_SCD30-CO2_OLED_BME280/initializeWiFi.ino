/*
  Based on WiFiSSLClient.ino in Wifi101 examples written by Arturo Guadalupi last revision November 2015
*/

void initializeWiFi() {
  WiFi.setPins(8, 7, 4, 2); // configure wifi pins
  delay(200);
  
  while (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    //while (true);
    delay(500);
  }

  int i = 0;
  while (i < 5) {   
    if (i==5) break;   
    i++;

    if (status != WL_CONNECTED) {
      
      if (i < 3) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid2);
        status = WiFi.begin(ssid2, pass2);   // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        if (status == WL_CONNECTED) i=5;
      }
      if (i == 3|| i == 4) {
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(ssid);
        status = WiFi.begin(ssid, pass);   // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
        if (status == WL_CONNECTED) i=5;
      }
      delay(10000);
      Serial.println(WiFi.status());     // output some diagnostic info

      }
    
  }
  printWiFiStatus();

}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  if (status == WL_CONNECTED){
  Serial.print("Connected to WiFi ");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.println();
  }
}
