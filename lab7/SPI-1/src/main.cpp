#include <Arduino.h>

#include <SPI.h>

const int slaveSelectPin = 10;

int id;
String to;
String mesType;
String payload;
int sum;

int idCount = -1;
int from = 2;
int distance = 0;

void sendMessage(String MType)
{
  id = idCount;
  idCount += 1;

  Serial.println("MessageStart");
  Serial.println("id: ");
  Serial.println(id);
  Serial.println("from: ");
  Serial.println(from);
  Serial.println("to: Master");
  Serial.println("type: DATA");
  Serial.println("payload: ");
  Serial.println(distance);
  Serial.println("sum: ");
  Serial.println(idCount + from);
  Serial.println("MessageEnd");
  Serial.println("Distance: ");
  Serial.println(distance);
}

void setup(void){
  Serial.begin(9600);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8); 
  digitalWrite(SS,HIGH); 
}

char inBuffer[2];
char outBuffer[3] = "ok";

void loop(void){
  if (Serial.available())
  {
      String command = Serial.readStringUntil('\n');
      command.trim();
      if (command.equalsIgnoreCase("dist"))
      {
        digitalWrite(SS, LOW);
        inBuffer[0] = SPI.transfer(outBuffer[0]);
        inBuffer[1] = SPI.transfer(outBuffer[1]);
        distance = inBuffer[0];
        distance += (int)inBuffer[1] << 8;
        distance += 33300;
        Serial.println("Master received from slave: ");
        Serial.println(distance);
        idCount += 2;
        sendMessage("GET");
      }
  }
  delay(1000);
}
