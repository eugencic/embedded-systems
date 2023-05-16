#include "TrafficLightFSM.h"

const int redPin = 13;
const int yellowPin = 12;
const int greenPin = 11;

TrafficLightFSM::TrafficLightFSM()
    : currentState(TrafficLightState::GREEN),
      previousState(TrafficLightState::GREEN) {}

void TrafficLightFSM::transitionToState(TrafficLightState nextState) 
{
  previousState = currentState;
  currentState = nextState;
}

void TrafficLightFSM::handleState() 
{
  switch (currentState) 
  {
    case TrafficLightState::GREEN:
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, HIGH);
      Serial.println("Traffic light color: GREEN");
      delay(2000);
      transitionToState(TrafficLightState::YELLOW);
      break;
    case TrafficLightState::YELLOW:
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(greenPin, LOW);
      Serial.println("Traffic light color: YELLOW");
      delay(1000);
      if (previousState == TrafficLightState::GREEN) 
      {
        transitionToState(TrafficLightState::RED);
      } else if (previousState == TrafficLightState::RED) 
      {
        transitionToState(TrafficLightState::GREEN);
      }
      break;
    case TrafficLightState::RED:
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      Serial.println("Traffic light color: RED");
      delay(2000);
      transitionToState(TrafficLightState::YELLOW);
      break;
  }
}
