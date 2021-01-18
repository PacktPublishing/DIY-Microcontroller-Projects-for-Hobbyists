/*
  Blink
  This program turns on the Blue Pill's internal LED on for one second, then off for two seconds, repeatedly.
  Version number: 1
  Date: Sept. 18, 2020
  Note: the internal LED is internally connected to port PC13.
  Written by Miguel Garcia-Ruiz.
 */

// the setup function runs only once.
void setup() 
{
  // it initializes digital pin PC13 as an output. Blue Pill's internal LED is also connected to it.
  pinMode(PC13, OUTPUT);  //PC13 IO port is labeled as "C13" on the Blue Pill.
}

// the loop function runs repeatedly forever.
void loop() //it's void because this function returns nothing.
{  
  digitalWrite(PC13, HIGH);   // it turns the LED on (logical HIGH)
  delay(1000);              // it waits for a second
  digitalWrite(PC13, LOW);    // it turns the LED off (logical LOW)
  delay(2000);              // it waits for two seconds
}
