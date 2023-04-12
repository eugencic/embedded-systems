#include "Motor.h"

Motor::Motor() {}

void Motor::setPin(int pin1, int pin2) 
{
    motorIn1 = pin1;
    motorIn2 = pin2;
}

void Motor::setup() 
{
    pinMode(motorIn1, OUTPUT);
    pinMode(motorIn2, OUTPUT);
}

void Motor::setRotation() 
{
    if (rotationDirection == 0)
    {
        analogWrite(motorIn1, motorSpeed);
        analogWrite(motorIn2, 0);
    }
    else if (rotationDirection == 1)
    {
        analogWrite(motorIn1, 0);
        analogWrite(motorIn2, motorSpeed);
    }
}

void Motor::increaseSpeed() 
{
    motorSpeed = motorSpeed + 25;
    if (motorSpeed > maxSpeed)
    {
      Serial.println("Maximum speed reached");
      motorSpeed = maxSpeed;
    }
    else Serial.println("Increasing the speed");
}

void Motor::decreaseSpeed() 
{
    motorSpeed = motorSpeed - 25;
    if (motorSpeed < minSpeed)
    {
      Serial.println("Minimum speed reached");
      motorSpeed = minSpeed;
    }
    else
      Serial.println("Decreasing the speed");
}

void Motor::changeRotation()
{
    if(rotationDirection == 0)
    {
      rotationDirection = 1;
    } 
    else rotationDirection = 0;
    Serial.println("Reversing the rotation");
}