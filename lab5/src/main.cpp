#include "LM35.h"
#include "MotorDriver.h"
#include "Relay.h"

#include <Arduino.h>

#define lm35Pin A0
#define potentiometerPin A1
#define relayPin 10
#define IN1 7
#define IN2 6
#define ENA 5

float targetTemperature = 50;
int currentTemperature = 0;
int potentiometerValue = 0;
int hysteresis = 3;
bool heaterState = false;

float pwmDutyCycle = 0;

int pid_duty_cycle_min = 0;
int pid_duty_cycle_max = 100;

float Kp = 10;
float Ki = 1;
float Kd = 1;

float previousError = 0;
float currentError = 0;
float integralError = 0;
float differentialError = 0;

int lastUpdateTime = 0;
int updateIntervalMs = 100;

LM35 lm(lm35Pin);
Relay relay(relayPin);
MotorDriver motor(IN1, IN2, ENA);

void setup()
{
  relay.init();
  pinMode(potentiometerPin, INPUT);
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  delay(2000);
  
  int currentTime = millis();
  if (currentTime - lastUpdateTime >= updateIntervalMs)
  {
    // Task 1
    lastUpdateTime = currentTime;
    currentTemperature = lm.readData();
    potentiometerValue = analogRead(potentiometerPin);
    targetTemperature = map(potentiometerValue, 0, 1023, 0, 100);
    if ((currentTemperature > targetTemperature + hysteresis) && heaterState)
    {
      relay.turnOff();
      heaterState = false;
    }
    if ((currentTemperature < targetTemperature - hysteresis) && !heaterState)
    {
      relay.turnOn();
      heaterState = true;
    }

    // Task 2
    float timeIntervalSec = (float)updateIntervalMs / 1000;
    currentError = currentTemperature - targetTemperature;
    integralError += currentError * timeIntervalSec;
    if (integralError < pid_duty_cycle_min / Ki)
    {
      integralError = pid_duty_cycle_min / Ki;
    }
    else if (integralError > pid_duty_cycle_max / Ki)
    {
      integralError = pid_duty_cycle_max / Ki;
    }
    differentialError = (currentError - previousError) / timeIntervalSec;
    pwmDutyCycle = -Kp * currentError + Ki * integralError + Kd * differentialError;
    if (pwmDutyCycle < pid_duty_cycle_min)
    {
      pwmDutyCycle = pid_duty_cycle_min;
    }
    if (pwmDutyCycle > pid_duty_cycle_max)
    {
      pwmDutyCycle = pid_duty_cycle_max;
    }
    motor.drive(pwmDutyCycle);
    previousError = currentError;

    float dutyCiclePercentage = pwmDutyCycle;

    Serial.print("Target temperature: ");
    Serial.print(targetTemperature);
    Serial.println(" C");
    Serial.print("Current temperature: ");
    Serial.print(currentTemperature);
    Serial.println(" C");

    Serial.print("Duty cycle percentage: ");
    Serial.print(dutyCiclePercentage);
    Serial.println("%");

    Serial.println(" ");

    delay(2000);
    }
}
