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
