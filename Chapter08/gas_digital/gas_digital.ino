/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 8: Gas sensor.
  Gas sensor with SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  May, 2021
*/

const int sensorPin = PB12;
boolean sensorValue = true;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
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
    delay(1000);
  }
}
