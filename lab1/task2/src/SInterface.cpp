#include "SInterface.h"
#include "Led.h"

SerialInterface::SerialInterface()
{
  ledState = LOW;
}

void SerialInterface::setup()
{
  Serial.begin(9600);
  Serial.println(startOutput);
  Serial.println(askOutput);
}

void SerialInterface::waitInput()
{
  Serial.println(waitOutput);
  while (Serial.available() == 0)
  {
  }
}

void SerialInterface::takeInput()
{
  delay(64);
  charsRead = Serial.readBytesUntil('\n', input, sizeof(input) - 1);
  input[charsRead] = 0;
  receivedInput = input;
  Serial.println(receivedInput);
}

bool SerialInterface::changeLight()
{
  if (receivedInput == turnOnMessage)
  {
    if (ledState == false)
    {
      ledState = true;
      Serial.println(receivedTurnOn);
      return true;
    }
    else
    {
      Serial.println(alreadyOn);
    }
  }
  else if (receivedInput == turnOffMessage)
  {
    if (ledState == true)
    {
      ledState = false;
      Serial.println(receivedTurnOff);
      return false;
    }
    else
    {
      Serial.println(alreadyOff);
    }
  }
  else
    Serial.println(wrongCommand);
}