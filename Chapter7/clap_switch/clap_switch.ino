/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 7: Clap switch: using a simple microphone to detect two clapping sounds in a row.
  A LED will blink after a clap is detected by the mic sensor.

  Ver. 1
  August, 2020
*/

const int MicAnalogPin = 0;                   // analog input pin
const int LedDigitalPin = PC13;               // digital output pin
const int ClapThreshold = 300;                // value for your clap sound
int ClapNumber = 0;                           // the clap counter

void setup() {
  Serial.begin(9600);                         // start analog sensing
  pinMode(LedDigitalPin, OUTPUT);             // set the digital pin as output
  pinMode(MicAnalogPin, INPUT);               // set the analogo pin as input
}

void loop() {
  int SoundValue = analogRead(MicAnalogPin);  // read sensor data from analog pin
  if (SoundValue > ClapThreshold) {           // clap detected?
    ClapNumber++;                             // increase the clap counter
    delay(500);                               // a 500 miliseconds pause
  }
  if (ClapNumber == 2) {                      // two claps?
    digitalWrite(LedDigitalPin, HIGH);        // turn led on
  }
  if (ClapNumber == 4) {                      // waiting for two more claps
    digitalWrite(LedDigitalPin, LOW);         // turn led off
    ClapNumber = 0;                           // restart the clap counter
  }
}
