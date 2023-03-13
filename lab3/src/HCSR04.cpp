#include "HCSR04.h"

HCSR04::HCSR04()
{
}

void HCSR04::setPin(int pin1, int pin2)
{
    trigPin = pin1;
    echoPin = pin2;
}

void HCSR04::setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float HCSR04::getData()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2.0;

    return distance;
}