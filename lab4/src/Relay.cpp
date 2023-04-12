#include "Relay.h"

Relay::Relay() {}

void Relay::setPin(int pin) 
{
  relayPin = pin;
}

void Relay::setup() 
{
  pinMode(relayPin, OUTPUT);
}

void Relay::switchLight(bool relayState) 
{
    bool state = relayState;
    if (state == true) 
    {
        Serial.println("Turning on the lamp");
        digitalWrite(relayPin, HIGH);
    } else 
    {
        Serial.println("Turning off the lamp");
        digitalWrite(relayPin, LOW);
    }
}