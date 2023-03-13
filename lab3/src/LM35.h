#ifndef LM35_H
#define LM35_H

#include <Arduino.h>

class LM35
{
private:
    int sensorPin;
    float resolution;

public:
    LM35();
    void setPin(int pin);
    int getSensorValue();
    float getTemperature(int sensorValue);
};

#endif