#include "LM35.h"

LM35::LM35() 
{
    resolution = 10;
}

void LM35::setPin(int pin)
{
    sensorPin = pin;
}

int LM35::getSensorValue()
{
    return analogRead(sensorPin);
}

float LM35::getTemperature(int sensorValue)
{
    float temperatureC = sensorValue / resolution;
    return temperatureC;
}