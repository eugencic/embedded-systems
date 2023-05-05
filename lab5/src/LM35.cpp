#include "LM35.h"

LM35::LM35(int pin)
{
    sensorPin = pin;
}

float LM35::readData()
{
    return analogRead(sensorPin) * 0.48875;
}
