#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "Motor.h"

#include <Arduino.h>

class MotorDriver
{
    private:
        Motor motor;
    public:
        MotorDriver(int pin1, int pin2, int pin3);
        void drive(int speed);
};

#endif
