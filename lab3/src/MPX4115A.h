#ifndef MPX4115A_H
#define MPX4115A_H

#include <Arduino.h>

class MPX4115A
{
private:
    int sensorPin;
public:
    MPX4115A();
    void setPin(int pin);
    int getSensorValue();
    float getPressure(int sensorValue);
};

#endif