#ifndef SINTERFACE_H
#define SINTERFACE_H

#include <Arduino.h>
#include <stdio.h>

class SerialInterface 
{
    private:
        byte ledState;
        String startOutput = "Hello! This is task 2";
        String askOutput = "Type 'turn on' to turn on the led, or 'turn off' to turn it off";
        String waitOutput = "Waiting for a command: ";
        int charsRead;
        char input[10];
        String turnOnMessage = "turn on";
        String receivedTurnOn = "Message received! Turning on the led";
        String alreadyOn = "The led is already on";
        String turnOffMessage = "turn off";
        String receivedTurnOff = "Message received! Turning off the led";
        String alreadyOff = "The led is already off";
        String wrongCommand = "There is no such command";
    public:
        String receivedInput;
        SerialInterface();
        void setup();
        void waitInput();
        void takeInput();
        bool changeLight();
};

#endif