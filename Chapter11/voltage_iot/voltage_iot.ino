/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 11: IoT Solar energy (voltage) measurement.
  Send voltage sensor data to Internet with NodeMCU.
  By Pedro Santana
  Ver. 1
  June, 2021
*/

#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password = "Password";

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
}

void loop() {
  double data = Serial.read();
  Serial.print("Voltage: ");
  Serial.println(data);
  delay(1000);
}
