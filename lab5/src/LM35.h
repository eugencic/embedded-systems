#ifndef LM35_H
#define LM35_H

#include <Arduino.h>

class LM35
{
    private:
        int sensorPin;
    public:
        LM35(int pin);
        float readData();
};

#endif
