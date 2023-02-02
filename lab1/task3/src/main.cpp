//#include "SInterface.h"
#include "CustomKeypad.h"
#include "Led.h"

#include <Arduino.h>
#include <stdio.h>

const int ledPin = 13;

// SerialInterface interface;
CustomKeypad keypad;
Keypad customKeypad = keypad.customKey();
Led led;

void setup() 
{
  // led.setPin(ledPin);
  // led.setup();
  Serial.begin(9600);
  // interface.setup();
}

void loop() 
{
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    Serial.println(customKey);
  }

    // if (customKey)
    // {
    //   Serial.println(customKey);
    // }
    // interface.waitInput();
    // delay(64);
    // interface.takeInput();
    // bool result = interface.changeLight();
    // if (result == true)
    // {
    //   led.switchLight(true);
    // }
    // else if (result == false)
    // {
    //   led.switchLight(false);
    // }
}