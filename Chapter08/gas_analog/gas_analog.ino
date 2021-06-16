/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 8: Gas sensor.
  Analog gas sensor with SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  May, 2021
*/

const int sensorPin = 0;
const int gasThreshold = 800;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  if (sensorValue > gasThreshold) {
    Serial.println("Gas presence detected");
  } else {
    Serial.println("No gas present");
  }
  delay(1000);
}
