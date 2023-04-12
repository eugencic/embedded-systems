#include "Relay.h"
#include "Motor.h"

#include <Arduino.h>

const int relayPin = 13;

const int motorIn1 = 10;
const int motorIn2 = 9;

int motorSpeed = 0;
int minSpeed = 0;
int maxSpeed = 255;

int rotationDirection = 0;

String turnOnLamp = "on";
String turnOffLamp = "off";
String increaseSpeed = "increase";
String decreaseSpeed = "decrease";
String changeRotation = "reverse";

Relay relay;
Motor motor;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Laboratory work Nr.4");
  relay.setPin(relayPin);
  relay.setup();
  motor.setPin(motorIn1, motorIn2);
  motor.setup();
}

void loop() 
{
  Serial.println("Waiting for a command: ");
  motor.setRotation();
  while (Serial.available() == 0)
  {
  }
  delay(64);
  char input[10];
  int charsRead = Serial.readBytesUntil('\n', input, sizeof(input) - 1);
  input[charsRead] = 0;
  String receivedInput = input;
  Serial.println(receivedInput);
  if (receivedInput == turnOnLamp) 
  {
    relay.switchLight(true);
  }
  else if (receivedInput == turnOffLamp) 
  {
    relay.switchLight(false);
  }
  else if (receivedInput == increaseSpeed) 
  {
    motor.increaseSpeed();
  }
  else if (receivedInput == decreaseSpeed)
  {
    motor.decreaseSpeed();
  }
  else if (receivedInput == changeRotation)
  {
    motor.changeRotation();
  }
  else Serial.println("Unknown command");
}