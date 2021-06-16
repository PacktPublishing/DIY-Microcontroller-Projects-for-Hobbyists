/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 8: Gas sensor.
  Gas sensor with SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  May, 2021
*/

#include <LedControlMS.h>

const int numDisplays = 1;
const int sensorPin = PB12;
boolean sensorValue = true;

LedControl lc = LedControl(7, 8, 5, numDisplays);

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() {
  sensorValue = digitalRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  if (sensorValue) {
    Serial.println("No gas present");
    delay(1000);
  } else  {
    Serial.println("Gas presence detected");
    lc.writeString(0, "A");
    delay(1000);
  }
}
