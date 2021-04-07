#include <ESP8266WiFi.h>

const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

WiFiServer server(80);

const int fromStm32Pin = 4; //D2 GPIO 4
int sensorValue = 2; // 0: Moist, 1: Dry, 2: Without reading
String header;
unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(fromStm32Pin, INPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();         
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /4/read") >= 0) {
              Serial.println("Reading the sensor");
              sensorValue = digitalRead(fromStm32Pin);
            }

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println("</style></head>");

            client.println("<body><h1>IoT plant pot moisture</h1>");

            if (sensorValue == 1) {
              client.println("<p>Soil is too dry</p>");
              client.println("<p><img width=\"50\" height=\"60\" src=\"https://cdn.pixabay.com/photo/2017/09/03/15/13/death-2710640_1280.png\"></p>");
            } else if (sensorValue == 0)  {
              client.println("<p>Soil is moist enough</p>");
              client.println("<p><img width=\"50\" height=\"60\" src=\"https://cdn.pixabay.com/photo/2013/07/13/11/51/earth-158806_1280.png\"></p>");
            } else {
              Serial.println("Press the button to read the sensor");
            }

            client.println("<p><a href=\"/read\"><button class=\"button\">Read sensor</button></a></p>");

            client.println("</body></html>");

            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
