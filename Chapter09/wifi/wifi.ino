/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 9: IoT temperature-logging system.
  Read sensor values from the SMT32 Blue Pill 
  and creates on the ESP-01 a web server to display the data.
  By Pedro Santana
  Ver. 2
  May, 2021
*/

#include <DallasTemperature.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
 
const char* ssid = "ssid";
const char* password = "password";

#define PIN_1_WIRE 0
OneWire pinWire(PIN_1_WIRE);
DallasTemperature sensors(&pinWire);
 
String strFrm = "<form action='read'><input type='submit' value='Read sensor'></form>";
 
ESP8266WebServer server(80);
 
void read_sensor() {
  Serial.print("Reading the sensor: ");
  sensors.requestTemperatures();
  int temp = sensors.getTempCByIndex(0);
  Serial.println(temp);
  server.send(200, "text/plain", String("Temperature: ") + String(temp));
}
 
void setup(void) {
  Serial.begin(115200);
  sensors.begin();
  WiFi.softAP(ssid, password);
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", [](){
    Serial.println("Incomming connection to server");
    server.send(200, "text/html", strFrm);
  });
  
  server.on("/read", read_sensor);
  
  server.begin();
}
 
void loop(void) {
  server.handleClient();
}
