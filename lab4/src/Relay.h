#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay
{
    private:
        int relayPin;
    public:
        Relay();
        void setPin(int pin);
        void setup();
        void switchLight(bool ledState);
};

#endif