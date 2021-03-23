#include <DallasTemperature.h>

#define PIN_1_WIRE PB12

OneWire pinWire(PIN_1_WIRE);
DallasTemperature sensors(&pinWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  Serial.print("Temp = ");
  Serial.print(temp); 
  Serial.println(" C");
  delay(1000);
}
