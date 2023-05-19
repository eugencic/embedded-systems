#include <Arduino.h>

#include <SPI.h>

#define BUFFER_SIZE 2
uint8_t outBuffer[2];
uint8_t inBuffer[2];
int buffCnt = 0;
const int trigPin = 5;
const int echoPin = 4;

void UltrasonicIntit(int trigPin, int echoPin) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int UltrasonicRead(int trigPin, int echoPin) {
    long duration;
    int distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    return distance;
}

void setup() {
    Serial.begin(9600);
    pinMode(MISO, OUTPUT);
    pinMode(SS, INPUT);
    SPCR |= _BV(SPE);
    SPI.attachInterrupt();
}

ISR(SPI_STC_vect) {
    if (buffCnt < BUFFER_SIZE) {
        inBuffer[buffCnt] = SPDR;
        SPDR = outBuffer[++buffCnt];
    }
    else {
        SPDR = 0;
    }
}

void loop() {
    int distance = UltrasonicRead(trigPin, echoPin);
    outBuffer[0] = distance & 0xFF;
    outBuffer[1] = distance >> 8;
    if (digitalRead(SS) == HIGH) {
        buffCnt = 0;
        SPDR = outBuffer[buffCnt];
    }
    else {
        Serial.println("Receiving: ");
        Serial.println(distance);
    }
    delay(1000);
}
