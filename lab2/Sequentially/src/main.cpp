#include "Button.h"
#include "Led.h"

#include <Arduino.h>
#include <stdio.h>

const int button1Pin = 11;
const int button2Pin = 10;
const int button3Pin = 9;

const int redLedPin = 13;
const int greenLedPin = 12;

byte lastButton1State = false;
byte lastButton2State = false;
byte lastButton3State = false;

byte redLedState = LOW;
byte greenLedState = LOW;

Button button1;
Button button2;
Button button3;

Led redLed;
Led greenLed;

byte blinksPerSecond = 0;
byte counter = 0;

byte lastGreenLedState = false;
byte lastGreenLedState2 = false;

static unsigned long lastButton2Time = 0;
static unsigned long lastButton3Time = 0;

void setup()
{
  button1.setPin(button1Pin);
  button1.setup();

  button2.setPin(button2Pin);
  button2.setup();

  button3.setPin(button3Pin);
  button3.setup();

  redLed.setPin(redLedPin);
  redLed.setup();

  greenLed.setPin(greenLedPin);
  greenLed.setup();

  Serial.begin(9600);
  Serial.println("This is laboratory work nr.2");
}

void task1() 
{
  bool button1State = button1.readButton();
  if (button1State != lastButton1State)
  {
    lastButton1State = button1State;
    if (button1State == false)
    {
      if (greenLedState == true)
      {
        if (blinksPerSecond == 0) 
        {
          greenLedState = false;
          delay(500);
        }
        else 
        {
          Serial.println("Decrease the frequency to 0 to turn off the green led");
        }
      }
      else
      {
        greenLedState = true;
        delay(500);
      }
      greenLed.switchLight(greenLedState);
    }
  }
}

void task2() 
{
  if (lastGreenLedState != greenLedState)
  {
    lastGreenLedState = greenLedState;
    if (greenLedState == false)
    {
      redLed.switchLight(true);
    }
    else
    {
      redLed.switchLight(false);
    }
  }
}

void task3()
{
  bool button2State = button2.readButton();
  if (button2State == lastButton2State && (millis() - lastButton2Time) > 50)
  {
    lastButton2State = button2State;
    lastButton2Time = millis();
    if (button2State == false)
    {
      blinksPerSecond++;
    }
  }

  bool button3State = button3.readButton();
  if (button3State == lastButton3State && (millis() - lastButton3Time) > 50)
  {
    lastButton3State = button3State;
    lastButton3Time = millis();
    if (button3State == false)
    {
      if (blinksPerSecond > 0)
      {
        blinksPerSecond--;
      }
      else if (blinksPerSecond == 0)
      {
        greenLed.switchLight(true);
      }
    }
  }

  if (blinksPerSecond > 0)
  {
    int interval = 1000 / blinksPerSecond;
    greenLed.switchLight(false);
    delay(interval / 2);
    greenLed.switchLight(true);
    delay(interval / 2);
  }
}

void task4() 
{
  if (lastGreenLedState2 != greenLedState)
  {
    lastGreenLedState2 = greenLedState;
    if (greenLedState == true)
    {
      Serial.println("Monitoring leds:");
      Serial.println("Green led status: on");
      Serial.println("Red led. Status: off");
    }
    else 
    {
      Serial.println("Monitoring leds:");
      Serial.println("Green led status: off");
      Serial.println("Red led status: on");
    }
  }

  if (counter != blinksPerSecond) 
  {
    if (counter < blinksPerSecond) 
    {
      Serial.print("Button 2 is pressed. Incrementing the number of blinks per second: ");
      Serial.println(blinksPerSecond);
    }
    else if (counter > blinksPerSecond) 
    {
      Serial.print("Button 3 is pressed. Decrementing the number of blinks per second: ");
      Serial.println(blinksPerSecond);
    }
    counter = blinksPerSecond;
  }
}

void loop() 
{
  task1();
  task2();
  task3();
  task4();
}