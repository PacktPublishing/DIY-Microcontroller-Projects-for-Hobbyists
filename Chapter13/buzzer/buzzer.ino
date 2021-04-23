/**
  Creative DIY Microcontroller Projects, published by Packt
  Chapter 13: COVID-19 two-meter distance meter.
  Programming a piezoelectric buzzer.
  By Pedro Santana
  Ver. 1
  April, 2021
*/

const int pinBuzzer = PB12;

void setup() { }

void loop() 
{
  tone(pinBuzzer, 1200);
  delay(250);

  noTone(pinBuzzer);
  delay(500);

  tone(pinBuzzer, 800);
  delay(250);

  noTone(pinBuzzer);
  delay(500);
}
