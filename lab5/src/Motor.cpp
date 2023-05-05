#include "Motor.h"

Motor::Motor()
{
}

void Motor::init(byte pin1, byte pin2, byte pin3)
{
    motorPin1 = pin1;
    motorPin2 = pin2;
    controlPin = pin3;

    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(controlPin, OUTPUT);
}

void Motor::changeSpeed(bool direction, int speed)
{
    if (direction)
    {
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        analogWrite(controlPin, speed);
    }
    else
    {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        analogWrite(controlPin, speed);
    }
}
