/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 11: IoT Solar energy (voltage) measurement.
  B25 voltage sensor with SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  June, 2021
*/

const int sensorPin = 0;

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  double voltageValue = map(sensorValue, 0, 1023, 0, 25);
  Serial.print("Voltage: ");
  //Serial.println(sensorValue);
  Serial.println(voltageValue);
  char SerialData[8];
  dtostrf(voltageValue, 6, 2, SerialData);
  //Serial1.write((int)voltageValue);
  Serial1.write(SerialData);
  delay(1000);
}
