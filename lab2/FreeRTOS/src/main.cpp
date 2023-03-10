#include "Button.h"
#include "Led.h"

#include <Arduino.h>
#include <stdio.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>

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

void task1(void *parameter)
{
  while (1) {
    bool button1State = button1.readButton();
    if (button1State != lastButton1State)
    {
      lastButton1State = button1State;
      if (button1State == false)
      {
        if (greenLedState == true)
        {
          greenLedState = false;
        }
        else
        {
          greenLedState = true;
        }
        greenLed.switchLight(greenLedState);
      }
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
  }
}

void task2(void *parameter)
{
  while (1) {
    Serial.println("t2");
    if (greenLedState == false)
    {
      redLed.switchLight(true);
      Serial.println("greenon");
    }
    else
    {
      redLed.switchLight(false);
      Serial.println("greenoff");
    }
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay for 1 second
  }
}

void task3(void *parameter)
{
  while (1)
  {
    bool button2State = button2.readButton();
    if (greenLedState == true)
    {
      if (button2State != lastButton2State)
      {
        lastButton2State = button2State;
        if (button2State == false)
        {
          blinksPerSecond++;
        }
      }
    }

    bool button3State = button3.readButton();
    if (greenLedState == true)
    {
      if (button3State != lastButton3State)
      {
        lastButton3State = button3State;
        if (button3State == false)
        {
          if (blinksPerSecond > 0)
          {
            blinksPerSecond--;
          }
        }
      }
    }

    if (blinksPerSecond > 0)
    {
      if (greenLedState == true)
      {
        int interval = 1000 / blinksPerSecond;
        greenLed.switchLight(false);
        delay(interval / 2);
        greenLed.switchLight(true);
        delay(interval / 2);
      }
    }
  }
}

void task4(void *parameter)
{
  while (1) {
    bool button1State = button1.readButton();
    if (button1State == false && greenLedState == true && lastGreenLedState == false)
    {
      Serial.println("The green led is on");
      lastGreenLedState = true;
    }
    else if (button1State == false && greenLedState == false && lastGreenLedState == true)
    {
      Serial.println("The red led is on");
      lastGreenLedState = false;
    }

    if (greenLedState == true && counter < blinksPerSecond)
    {
      Serial.print("Button 2 is pressed. Incrementing the number of blinks per second: ");
      Serial.println(blinksPerSecond);
      counter = blinksPerSecond;
    }

    if (greenLedState == true && counter > blinksPerSecond)
    {
      Serial.print("Button 3 is pressed. Decrementing the number of blinks per second: ");
      Serial.println(blinksPerSecond);
      counter = blinksPerSecond;
    }
  }
}

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

  xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
  xTaskCreate(task2, "Task 2", 1000, NULL, 2, NULL);
  // xTaskCreate(task3, "Task 3", 1000, NULL, 1, NULL);
  // xTaskCreate(task4, "Task 4", 1000, NULL, 2, NULL);
}

void loop()
{
  // task1();
  // task2();
  // task3();
  // task4();
}