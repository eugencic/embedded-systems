#include "LM35.h"
#include "LDR.h"
#include "MPX4115A.h"
#include "HCSR04.h"

#include <Arduino.h>
#include <stdio.h>
#include <Wire.h>

const int lm35Pin = A0;
const int ldrPin = A1;
const int mpx4115a = A2;
const byte trigPin = 13;
const byte echoPin = 12;

LM35 temperatureSensor;
LDR lightSensor;
MPX4115A pressureSensor;
HCSR04 ultrasonicSensor;

void setup()
{
  temperatureSensor.setPin(lm35Pin);
  lightSensor.setPin(ldrPin);
  pressureSensor.setPin(mpx4115a);
  ultrasonicSensor.setPin(trigPin, echoPin);
  ultrasonicSensor.setup();

  Serial.begin(9600);
  Serial.println("This is laboratory work nr.3");
}

void loop() 
{
  int tSensorValue = temperatureSensor.getSensorValue();
  float temperatureC = temperatureSensor.getTemperature(tSensorValue);
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" degrees Celsius");

  int lSensorValue = lightSensor.getSensorValue();
  float lux = lightSensor.getLight(lSensorValue);
  Serial.print("Light intensity: ");
  Serial.print(lux);
  Serial.println(" Lux");

  int pSensorValue = pressureSensor.getSensorValue();
  float pressure = pressureSensor.getPressure(pSensorValue);
  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" kPa");

  float distance = ultrasonicSensor.getData();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(3000);
}