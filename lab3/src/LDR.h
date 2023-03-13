#ifndef LDR_H
#define LDR_H

#include <Arduino.h>

class LDR
{
private:
    int sensorPin;
    int maxAdcReading;
    float adcRefVoltage;
    float refResistance;
    float luxCalcScalar;
    float luxCalcExponent;

public:
    LDR();
    void setPin(int pin);
    int getSensorValue();
    float getLight(int sensorValue);
};

#endif