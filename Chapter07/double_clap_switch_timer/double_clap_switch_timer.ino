/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 7: Clap switch: using a simple microphone to detect two clapping sounds in a row.
  Exercice 3: A LED will blink after two claps are detected by the mic sensor in a timeframe.
  Ver. 1
  August, 2020
*/

const int MicAnalogPin = 0;                   // analog input pin
const int LedDigitalPin = PC13;               // digital output pin
const int ClapThreshold = 300;                // value for your clap sound
int ClapNumber = 0;                           // clap counter
bool LedState = false;                        // state of the LED

unsigned long FirstClapEvent = 0;             // Time for the first clap
unsigned long SecondClapEvent = 0;            // Time for the second clap

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
    FirstClapEvent = (ClapNumber == 1) ? millis() : FirstClapEvent; // Record the time of the first clap
  }
  if (ClapNumber == 2) {                      // two claps?
    SecondClapEvent = millis();               // Record the time of the second clap
    if (SecondClapEvent - FirstClapEvent < 30000) {   // Verify the timeframe between claps
      if (LedState) {                                 // Verify the LED state (ON or OFF)
        digitalWrite(LedDigitalPin, HIGH);            // turn led on
      } else {
        digitalWrite(LedDigitalPin, LOW);             // turn led off
      }
      ClapNumber = 0;                                 // Reset the clap number
      LedState = !LedState;                           // flag the state for the LED
      FirstClapEvent = 0;                             // Reset the clap events
      SecondClapEvent = 0;
    }
  }
}
