/*
  Write to Google Sheets through a Wifi POST HTTP1.1 request to a Google script.
*/
void payloadUpload(String payload) {
  if (WiFi.status() == WL_CONNECTED) {
    


  if (!client.connected()) {
    initializeClient();
  }

  payload = payload_base + "\"" + payload + "\"}";
  Serial.print("payload: "); Serial.println(payload);

  // Make a HTTP request:
  client.println("POST /macros/s/AKfycbz9ayTQhGrJjgftPum5e2-s6uDvvFLXmuj1AQkhrODPRNgP_QMG3bkNKPlMhDI47E7Brg/exec?value=Hello HTTP/1.1"); // for ricado's googlesheet
  client.println("Host: script.google.com");
  client.println("Content-Type: application/x-www-form-urlencoded");
  //client.println("Connection: close");
  client.print("Content-Length: ");
  client.println(payload.length());
  client.println();
  client.print(payload);
  client.println();
  delay(200);

  Serial.println("Response: ");
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  Serial.println();

  client.stop();
  if (!client.connected()) {
    Serial.println("disconnected from server.");
  }
  
  }
  else Serial.println("No WiFi Connection. Cannot complete payload");;
}


void initializeClient() {
  Serial.print("\nStarting connection to server... ");
  if (client.connectSSL(server, 443)) {      // if you get a connection, report back via serial:
    Serial.print("connected to ");
    Serial.println(server);
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }
  }
  else {
    Serial.print("No connection to server: "); Serial.println(server);
    //while (1);
  }
}
