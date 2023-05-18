#include "TrafficLightFSM.h"

TrafficLightFSM::TrafficLightFSM(String state)
{
    if (state == "GREEN") {
        currentState = TrafficLightState::GREEN;
    } else if (state == "YELLOW") {
        currentState = TrafficLightState::YELLOW;
    } else if (state == "RED") {
        currentState = TrafficLightState::RED;
    } else {
        currentState = TrafficLightState::GREEN;
    }
}

void TrafficLightFSM::setPins(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
{
  redPin1 = pin1;
  yellowPin1 = pin2;
  greenPin1 = pin3;
  redPin2 = pin4;
  yellowPin2 = pin5;
  greenPin2 = pin6;
}

void TrafficLightFSM::setup() 
{
  pinMode(redPin1, OUTPUT);
  pinMode(yellowPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
}

void TrafficLightFSM::transitionToState(TrafficLightState nextState) 
{
  currentState = nextState;
}

void TrafficLightFSM::handleState() 
{
  switch (currentState) 
  {
    case TrafficLightState::GREEN:
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin1, LOW);
      digitalWrite(greenPin1, HIGH);
      digitalWrite(redPin2, HIGH);
      digitalWrite(yellowPin2, LOW);
      digitalWrite(greenPin2, LOW);
      Serial.println("Traffic light 1 color: GREEN");
      Serial.println("Traffic light 2 color: RED");
      delay(2000);
      transitionToState(TrafficLightState::YELLOW);
      break;
    case TrafficLightState::YELLOW:
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin1, HIGH);
      digitalWrite(greenPin1, LOW);
      digitalWrite(redPin2, HIGH);
      digitalWrite(yellowPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      Serial.println("Traffic light 1 color: YELLOW");
      Serial.println("Traffic light 2 color: RED + YELLOW");
      delay(1000);
      transitionToState(TrafficLightState::RED);
      break;
    case TrafficLightState::RED:
      digitalWrite(redPin1, HIGH);
      digitalWrite(yellowPin1, LOW);
      digitalWrite(greenPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin2, LOW);
      digitalWrite(greenPin2, HIGH);
      Serial.println("Traffic light 1 color: RED");
      Serial.println("Traffic light 2 color: GREEN");
      delay(2000);
      transitionToState(TrafficLightState::REDYELLOW);
      break;
    case TrafficLightState::REDYELLOW:
      digitalWrite(redPin1, HIGH);
      digitalWrite(yellowPin1, HIGH);
      digitalWrite(greenPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin2, HIGH);
      digitalWrite(greenPin2, LOW);
      Serial.println("Traffic light 1 color: RED + YELLOW");
      Serial.println("Traffic light 2 color: YELLOW");
      delay(1000);
      transitionToState(TrafficLightState::GREEN);
      break;
  }
}
