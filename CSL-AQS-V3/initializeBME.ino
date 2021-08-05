// Adafruit BME280 T P RH sensor

void initializeBME()  {
  Serial.print("starting BME280... ");
  unsigned bmeStatus = bme.begin();
  // You can also pass in a Wire library object like &Wire2
  // bmeStatus = bme.begin(0x76, &Wire2)
  if (!bmeStatus) {
    Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
    Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(), 16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
  }
  else
    Serial.println("BME ok");
}
