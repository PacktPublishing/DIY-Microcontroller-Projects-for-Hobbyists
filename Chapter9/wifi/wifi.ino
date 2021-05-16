/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 9: IoT temperature-logging system.
  Read sensor values from the SMT32 Blue Pill 
  and creates on the ESP-01 a web server to display the data.
  By Pedro Santana
  Ver. 1
  March, 2021
*/
#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);

  WiFi.begin("YOUR_SSID", "YOUR_PASSWORD");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print("Conectado, dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
