#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
    private:
        int motorIn1;
        int motorIn2;
        int motorSpeed = 0;
        int minSpeed = 0;
        int maxSpeed = 255;
        int rotationDirection = 0;
    public:
        Motor();
        void setPin(int pin1, int pin2);
        void setup();
        void setRotation();
        void increaseSpeed();
        void decreaseSpeed();
        void changeRotation();
};

#endif