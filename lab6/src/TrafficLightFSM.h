#ifndef TRAFFIC_LIGHT_FSM_H
#define TRAFFIC_LIGHT_FSM_H

#include <Arduino.h>

enum class TrafficLightState 
{
  RED,
  YELLOW,
  GREEN
};

class TrafficLightFSM 
{
public:
  TrafficLightFSM();
  void transitionToState(TrafficLightState nextState);
  void handleState();

private:
  TrafficLightState currentState;
  TrafficLightState previousState;
};

#endif
