/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 10: IoT plant pot moisture sensor.
  Soil moisture sensor with SMT32 Blue Pill.
  By Pedro Santana
  Ver. 1
  April, 2021
  
*/

const int sensorPin = PB12;
const int toInternetPin = PC13;

int sensorValue = 0;
  
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(toInternetPin, OUTPUT);
}

void loop() {
  sensorValue = digitalRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  if (sensorValue == 1) {
    digitalWrite(toInternetPin, HIGH);
    Serial.println("Soil is too dry");
    delay(1000);
  } else  {
    digitalWrite(toInternetPin, LOW);
    Serial.println("Soil is moist enough");
    delay(1000);
  }
}
