// Adafruit OLED display 
void initializeOLED()  {  
    Serial.begin(11500);
    
    Serial.println("OLED ok");

    Serial.println("128x64 OLED FeatherWing test");
    display.begin(0x3C, true); // Address 0x3C default
    display.setRotation(1);
    pinMode(BUTTON_A, INPUT_PULLUP);
    pinMode(BUTTON_B, INPUT_PULLUP);
    pinMode(BUTTON_C, INPUT_PULLUP);
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0, 0);
    display.display();
}
