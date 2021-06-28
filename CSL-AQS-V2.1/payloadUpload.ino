/*
  Write to Google Sheets through a Wifi POST HTTP1.1 request to a Google script.
*/
void payloadUpload(String payload) {
  int status = 0;
  
  for (int i = 1; i < 5; i++) {
    status = WiFi.begin(ssid, pass);
    delay(500);

    if (WiFi.status() == WL_CONNECTED) {
      if (!client.connected()) {
        initializeClient();
      }
      payload = payload_base + String("\"") + payload + String("\"}");
      Serial.print("payload: ");  Serial.println(payload);
      // Make a HTTP request:
      client.println(POSTCommand);
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
      };
      WiFi.end();
      break;
    }
    else {
      Serial.print("Trying to connect to Wifi : "); Serial.println(i);
    }
  }
  if (status != WL_CONNECTED)
    Serial.println("Continuing without WiFi"); Serial.println(status);
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
