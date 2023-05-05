#include "Relay.h"

Relay::Relay(int pin)
{
    relayPin = pin;
}

void Relay::init()
{
    pinMode(relayPin, OUTPUT);  
    digitalWrite(relayPin, LOW);  
}

void Relay::turnOn()
{
    digitalWrite(relayPin, HIGH); 
}

void Relay::turnOff()
{
    digitalWrite(relayPin, LOW); 
}
