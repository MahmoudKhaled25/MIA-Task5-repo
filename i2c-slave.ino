#include <Wire.h>

#define SLAVE_ADDRESS 8
#define LED_PIN 9

void setup()
{
  Wire.begin(SLAVE_ADDRESS);                // Initialize I2C communication as slave with address 8
  Wire.onReceive(receiveEvent);             // Register receive event
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  
}

void receiveEvent(int numBytes) 
{
  if (numBytes >= 2) 
  {
    int buttonState1 = Wire.read();  // Read button state 1
    int buttonState2 = Wire.read();  // Read button state 2
    
    int intensity = 0;
    String message = "No message";
    
    if (buttonState1 == 1 && buttonState2 == 0) 
    {
      intensity = 128;   // 50% of maximum
      message = "Vector focused";
    } 
    else if (buttonState1 == 0 && buttonState2 == 1) 
    {
      intensity = 191;   // 75% of maximum
      message = "Vector distracted";
    } 
    else if (buttonState1 == 1 && buttonState2 == 1) 
    {
      intensity = 255;   // 100% of maximum
      message = "Glitch";
    }
    else {}
    analogWrite(LED_PIN, intensity);   // Control LED intensity using PWM
    Serial.println(message);            // Print message to Serial Monitor
  }
}