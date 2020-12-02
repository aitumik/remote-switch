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

  String request = client.readStringUntil('\r');
  // I want to see how the request is from the app
  Serial.println(request);
  client.flush();

  int value = LOW;
  //if there is LED=ON on the request then turn on the led
  if(request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin,HIGH);
    //set the value to high to allow toggling
    value = HIGH;
  }
  if(request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPing,LOW);
    value = LOW;
  }

  client.println("The led is now: ");
  if(value == HIGH) {
    client.print("ON");
  } else {
    client.print("OFF");
  }
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
