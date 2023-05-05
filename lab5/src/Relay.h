#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay
{
    private:
        int relayPin;
    public:
        Relay(int pin);
        void init();
        void turnOn();
        void turnOff();
};

#endif
