#ifndef TRAFFIC_LIGHT_FSM_H
#define TRAFFIC_LIGHT_FSM_H

#include <Arduino.h>

enum class TrafficLightState 
{
  RED,
  REDYELLOW,
  GREEN,
  YELLOW,
};

class TrafficLightFSM 
{
public:
  TrafficLightFSM(String state);
  int redPin1;
  int yellowPin1;
  int greenPin1;
  int redPin2;
  int yellowPin2;
  int greenPin2;
  void setPins(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6);
  void setup();
  void transitionToState(TrafficLightState nextState);
  void handleState();

private:
  TrafficLightState currentState;
  TrafficLightState previousState;
};

#endif
