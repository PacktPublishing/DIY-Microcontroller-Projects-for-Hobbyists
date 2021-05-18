/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 9: IoT temperature-logging system.
  Read temperature sensor values from the SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  March, 2021
*/
#include <DallasTemperature.h>

#define PIN_1_WIRE PB12

OneWire pinWire(PIN_1_WIRE);
DallasTemperature sensors(&pinWire);

void setup() {
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  Serial.print("Temperature = ");
  Serial.print(temp); 
  Serial.println(" ºC");
  delay(1000);
}
