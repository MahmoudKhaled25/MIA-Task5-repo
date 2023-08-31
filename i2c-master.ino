#include <Wire.h>

#define SLAVE_ADDRESS 8
#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3

void setup() {
  Wire.begin();        // Initialize I2C communication
  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
}

void loop() {
  int buttonState1 = digitalRead(BUTTON_PIN_1);
  int buttonState2 = digitalRead(BUTTON_PIN_2);
  
  Wire.beginTransmission(SLAVE_ADDRESS);   // Start communication with Slave Arduino
  Wire.write(buttonState1);    // Send button state 1
  Wire.write(buttonState2);    // Send button state 2
  Wire.endTransmission();      // End transmission
  
  delay(100);   // Delay between each transmission
}
