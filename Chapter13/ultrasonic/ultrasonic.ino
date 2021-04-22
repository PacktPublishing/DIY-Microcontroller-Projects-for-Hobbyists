/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 13: COVID-19 two-meter distance meter.
  Writing a program for getting data from the ultrasonic sensor.
  By Pedro Santana
  Ver. 1
  April, 2021 
*/

const int pinTrigger = PC14;
const int pinEcho = PC13;

long soundWaveTime;
long distanceMeasurement;

void setup() {
  Serial.begin(9600);
  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinTrigger, LOW);
}

void loop()
{
  digitalWrite(pinTrigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(pinTrigger, LOW);
  
  soundWaveTime = pulseIn(pinEcho, HIGH);
  distanceMeasurement = soundWaveTime/59;
  
  Serial.print("Distance: ");
  Serial.print(distanceMeasurement);
  Serial.println("cm");
  delay(500);
}
