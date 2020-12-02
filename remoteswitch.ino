#include <ESP8266WiFi.h>

const char* ssid = "MUGO"; //replace this with your own ssid
const char* password = "mugo2020"; //replace this with your password

int ledPin = 13;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPing,LOW);

  //connect to wifi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("");
  Serial.println("The device connected to the WiFi successfully\r\n");

  //setup the server
  server.begin();
  Serial.print("The server is started\r\n");

  //get the IP address
  Serial.println(WiFi.localIP());
  
}

void loop() {
  WiFiClient client = server.available();
  if(!client) {
    return;
  }

  Serial.println("Some one just connected\r\n");
  while(!client.available()) {
    delay(1);
  }
}
