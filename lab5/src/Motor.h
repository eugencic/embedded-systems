#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor
{
    private:
        byte motorPin1;
        byte motorPin2;
        byte controlPin;

    public:
        Motor();
        void init(byte pin1, byte pin2, byte pin3);
        void changeSpeed(bool direction, int speed); 
};

#endif
