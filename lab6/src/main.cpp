#include "ElevatorFSM.h"
#include "TrafficLightFSM.h"

#include <Arduino.h>

const int numButtons = 8;
const int numElevatorButtons = 8;

int floorButtons[numButtons] = {10, 9, 8, 7, 6, 5, 4, 3};
int elevatorButtons[numElevatorButtons] = {21, 20, 19, 18, 17, 16, 15, 14};

ElevatorFSM elevator(floorButtons, numButtons, elevatorButtons, numElevatorButtons);

const int redPin1 = 13;
const int yellowPin1 = 12;
const int greenPin1 = 11;

const int redPin2 = 24;
const int yellowPin2 = 25;
const int greenPin2 = 26;

TrafficLightFSM* trafficLight = new TrafficLightFSM("GREEN");

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

    trafficLight->setPins(redPin1, yellowPin1, greenPin1, redPin2, yellowPin2, greenPin2);
    trafficLight->setup();

}

void loop()
{
    //elevator.handleState();
    trafficLight->handleState();
}
