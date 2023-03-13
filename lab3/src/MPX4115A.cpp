#include "MPX4115A.h"

MPX4115A::MPX4115A()
{
}

void MPX4115A::setPin(int pin)
{
    sensorPin = pin;
}

int MPX4115A::getSensorValue()
{
    return analogRead(sensorPin);
}

float MPX4115A::getPressure(int sensorValue)
{
    float pressure = ((float)sensorValue / (float)1023 + 0.095) / 0.009;
    return pressure;
}