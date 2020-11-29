/*program that reads temperature and humidity values from the DHT11 sensor module.
 * Written by Miguel Garcia-Ruiz
 * November 17, 2020
 * Ver. 1
 * To open the serial monitor: click on Tools/Serial Monitor on Arduino IDE's menu.
 * Make sure to set up the serial monitor to 9600 Bauds.
 */
#include <DHT.h> //library for reading DHT11 values
#define DHT11_data_pin PB12 /* DHT11's digital data (signal) B12 pin is connected to DHT11*/ 
 DHT dht(DHT11_data_pin, DHT11); //Sets up DHT11
void setup() {
  Serial.begin(9600); //Initializes serial monitor
  while (!Serial);
  Serial.println("Opening serial comm.");
  
  dht.begin(); //Initializes DHT11 library
}

void loop() {
  float humidity = dht.readHumidity(); //gets humidity value from DHT11
  float temperature=dht.readTemperature(); // gets temp. value from DHT11
  Serial.println("Humidity: "+String(humidity)); //prints out humidity on the Arduino IDE's serial monitor 
  Serial.println("Temperature: "+String(temperature)); //prints out temp. on the Arduino IDE's serial monitor
  delay(1000); //waits 1 second before getting new humidity and temperature readings
}
