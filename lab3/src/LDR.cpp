#include "LDR.h"

LDR::LDR()
{
    maxAdcReading = 1023;
    adcRefVoltage = 5.0;
    refResistance = 5;
    luxCalcScalar = 12518931;
    luxCalcExponent = -1.405;
}

void LDR::setPin(int pin)
{
    sensorPin = pin;
}

int LDR::getSensorValue()
{
    return analogRead(sensorPin);
}

float LDR::getLight(int sensorValue)
{
    float resistorVoltage = (float)sensorValue / maxAdcReading * adcRefVoltage;
    float ldrVoltage = adcRefVoltage - resistorVoltage;
    float ldrResistance = ldrVoltage / resistorVoltage * refResistance;
    float lux = luxCalcScalar * pow(ldrResistance, luxCalcExponent);
    return lux;
}