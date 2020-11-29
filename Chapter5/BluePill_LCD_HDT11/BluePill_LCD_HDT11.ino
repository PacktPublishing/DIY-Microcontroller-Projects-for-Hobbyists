/*program that reads temperature and humidity values from the DHT11 sensor module.
 * The humidity and temperature are displayed on a 1602 16x2 LCD.
 * Written by Miguel Garcia-Ruiz
 * November 17, 2020
 * Ver. 1
 */
#include <DHT.h> //library for reading DHT11 values
#include <math.h> //library for the round() function
#include <LiquidCrystal.h> // library for using the 1602 LCD
/*
* LCD's VSS pin to GND
* LCD's VDD pin to 5V
* LCD's VO pin to POT (variable resistor)
* LCD's RS pin to digital input pin PB11
* LCD's RW pin to GND
* LCD's EN pin to digital input pin PB10
* LCD's D0 to D3 pins are not used
* LCD's D4 pin to digital input pin PB0
* LCD's D5 pin to digital input pin PA7
* LCD's D6 pin to digital input pin PA6
* LCD's D7 pin to digital input pin PA5
* LCD's BL+ pin to 5V
* LCD's BL- pin to GND
*/
const int rs = PB11, en = PB10, d4 = PB0, d5 = PA7, d6 = PA6, d7 = PA5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //define data pins from LCD

#define DHT11_data_pin PB12 /* DHT11's digital data (signal) B12 pin is connected to DHT11*/ 
DHT dht(DHT11_data_pin, DHT11); //Sets up DHT11

void setup() {
  dht.begin(); //Initializes DHT11 library
  lcd.begin(16, 2);  //Initializes LCD
}

void loop() {
  float humidity = dht.readHumidity(); //gets humidity value from DHT11
  float temperature=dht.readTemperature(); // gets temp. value from DHT11
  lcd.setCursor(0, 0); // LCD's column 0, row 0
  lcd.print("Humidity: "+String(round(humidity))+"%   "); //prints out humidity on the Arduino IDE's serial monitor 
  lcd.setCursor(0,1); //LCD's column 0, row 1
  lcd.print("Temp.: "+String(temperature)+"C   "); //prints out temp. on the Arduino IDE's serial monitor
  delay(1000); //waits 1 second before getting new humidity and temperature readings
}
