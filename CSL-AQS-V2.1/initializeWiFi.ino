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
  status = WiFi.status();
  for (int i = 1; i < 5; i++) {
    if (status != WL_CONNECTED) {
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      if (pass != "") // if no password
        status = WiFi.begin(ssid, pass);  
      else
        status = WiFi.begin(ssid);   
    }
    else {
      Serial.print("Connected to WiFi -");
      Serial.println(i);
      break;
    }
    delay(1000);
  }
  
  if (status != WL_CONNECTED)
    Serial.println("Continuing without WiFi");     // output some diagnostic info
  printWiFiStatus();
  display.print("SSID :");
  display.println(ssid);
  display.print("GSSID :");
  display.println(GSSD_ID);
  display.display(); // actually display all of the above
  
  WiFi.end(); // end wifi. will be restarted each upload.
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  if (status == WL_CONNECTED) {
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
