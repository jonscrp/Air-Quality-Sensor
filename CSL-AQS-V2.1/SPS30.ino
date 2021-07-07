/*  Sensirion SPS20 PM sensor. 
 *   
 *    functions:
 *    - void initializeSPS30()
 *    - String read_sps30 
 *    It returns a string with the 10 data fields mass for 1um, 2.5um, 4um, 10um; 
 *   concentration for 0.5um, 1um, 2.5um, 10um and average particle size in um
 */

String read_sps30()
{ static bool header = true;
  uint8_t ret, error_cnt = 0;
  struct sps_values val;
  // loop to get data
  do {
    ret = sps30.GetValues(&val);
    // data might not have been ready
    if (ret == ERR_DATALENGTH) {
      if (error_cnt++ > 3)
        Serial.println("Error during reading values: ");
      delay(1000);
    }
    else if (ret != ERR_OK)
      Serial.println("Error during reading values: ");
  } while (ret != ERR_OK);

  // only print header first time
  if (header) {
    Serial.println("PM data from Sensirion SPS30 is in the following order...");
    Serial.println("-------------Mass -----------    ------------- Number --------------   -Average-");
    Serial.println("     Concentration [μg/m3]             Concentration [#/cm3]             [μm]");
    Serial.println("mP1.0,\tmP2.5,\tmP4.0,\tmP10,\tnP0.5,\tnP1.0,\tnP2.5,\tnP4.0,\tnP10,\tPartSize");
    header = false;
  }
//  String outString = String(val.MassPM1) + String(",\t") + String(val.MassPM2) + String(",\t") + String(val.MassPM4) + String(",\t") + String(val.MassPM10) + String(",\t") +
//                     String(val.NumPM0) + String(",\t") + String(val.NumPM1) + String(",\t") + String(val.NumPM2) + String(",\t") + String(val.NumPM4) + String(",\t") +
//                     String(val.NumPM10) + String(",\t") + String(val.PartSize);
  String outString = String(val.MassPM1) + String(", ") + String(val.MassPM2) + String(", ") + String(val.MassPM4) + String(", ") + String(val.MassPM10) + String(", ") +
                     String(val.NumPM0) + String(", ") + String(val.NumPM1) + String(", ") + String(val.NumPM2) + String(", ") + String(val.NumPM4) + String(", ") +
                     String(val.NumPM10) + String(", ") + String(val.PartSize);
  return (outString);
}

void initializeSPS30() {
  pinMode(11, OUTPUT); digitalWrite(11, HIGH); // this is to turn on the miniBoost 3.7V->5V converter for SPS30
  Serial1.begin(115200); // to communicate with SPS30 on RX,\tX
  // Initialize SPS30 library
  if (! sps30.begin(&Serial1))
    Serial.println("Could not set serial communication channel");
  // check for SPS30 connection
  if (!sps30.probe()) {
    Serial.println("could not probe / connect with SPS30");}
  //  else
  //    Serial.println("Detected SPS30");
  // reset SPS30 connection
  if (!sps30.reset())
    Serial.println("could not reset SPS30 ");
  // start measurement
  if (sps30.start())
    Serial.println("Started SPS30");
  else
    Serial.println("Could NOT start SPS30");
}
