/**
  Creative DIY Microcontroller Projects with C, published by Packt
  Chapter 10: IoT plant pot moisture sensor.
  Read sensor values from the SMT32 Blue Pill 
  and creates on the NodeMCU a web server to display the data.
  By Pedro Santana
  Ver. 1
  April, 2021
*/
#include <ESP8266WiFi.h>

const char* ssid = "Your_SSID";
const char* password = "Your_Password";

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
  Serial.print("Connecting to WiFi network: ");
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
            client.println("<title>IoT plant pot moisture</title>");
            client.println("<link rel=\"stylesheet\" href=\"https://use.fontawesome.com/releases/v5.7.2/css/all.css\" crossorigin=\"anonymous\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".sensorButton { background-color:#f9f9f9; border-radius:6px; border:1px solid #dcdcdc; display:inline-block;");
            client.println("cursor:pointer; color:#666666; font-size:24px; padding:12px 30px; text-decoration:none; }");
            client.println(".sensorButton:hover { background-color:#e9e9e9; }");
            client.println(".sensorButton:active { position:relative; top:1px; }");
            client.println("</style></head>");

            client.println("<body><h1>IoT plant pot moisture</h1>");

            if (sensorValue == 1) {
              client.println("<p>Soil is too dry</p>");
              client.println("<p><img width=\"50\" height=\"60\" src=\"https://raw.githubusercontent.com/PacktPublishing/Creative-DIY-Microcontroller-Projects/master/Chapter10/images/dry_plant.png\"></p>");
            } else if (sensorValue == 0)  {
              client.println("<p>Soil is moist enough</p>");
              client.println("<p><img width=\"50\" height=\"60\" src=\"https://raw.githubusercontent.com/PacktPublishing/Creative-DIY-Microcontroller-Projects/master/Chapter10/images/green_plant.png\"></p>");
            } else {
              client.println("<p>Press the button to read the sensor</p>");
            }

            client.println("<p><a href=\"/4/read\"><button class=\"sensorButton\"><i class=\"fas fa-satellite-dish\"></i> Read sensor</button></a></p>");

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
