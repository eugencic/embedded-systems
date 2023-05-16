#include "ElevatorFSM.h"
#include "TrafficLightFSM.h"

#include <Arduino.h>

const int numButtons = 8;
const int numElevatorButtons = 8;

int floorButtons[numButtons] = {10, 9, 8, 7, 6, 5, 4, 3};
int elevatorButtons[numElevatorButtons] = {21, 20, 19, 18, 17, 16, 15, 14};

ElevatorFSM elevator(floorButtons, numButtons, elevatorButtons, numElevatorButtons);

const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

TrafficLightFSM trafficLight;

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < numButtons; i++)
    {
        pinMode(floorButtons[i], INPUT_PULLUP);
    }

    for (int i = 0; i < numElevatorButtons; i++)
    {
        pinMode(elevatorButtons[i], INPUT_PULLUP);
    }

    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
}

void loop()
{
    elevator.handleState();
    //trafficLight.handleState();
}
