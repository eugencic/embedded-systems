#ifndef HCSR04_H
#define HCSR04_H

#include <Arduino.h>

class HCSR04
{
private:
    int trigPin;
    int echoPin;

public:
    HCSR04();
    void setPin(int pin1, int pin2);
    void setup();
    float getData();
};

#endif