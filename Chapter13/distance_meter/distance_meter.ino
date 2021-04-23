/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 13: COVID-19 two-meter distance meter.
  Writing a program to play a sound with the piezo buzzer.
  By Pedro Santana
  Ver. 1
  April, 2021 
*/

const int pinTrigger = PC14;
const int pinEcho = PC13;
const int pinBuzzer = PB12;
const int distanceSafety = 200;

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

  if (distanceMeasurement < distanceSafety) {
    tone(pinBuzzer, 1200);
    delay(250);
  
    noTone(pinBuzzer);
    delay(500);
  
    tone(pinBuzzer, 800);
    delay(250);
  
    noTone(pinBuzzer);
    delay(500);
  }
}
