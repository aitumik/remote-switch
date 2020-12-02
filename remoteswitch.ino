#include <ESP8266WiFi.h>

const char* ssid = "MUGO"; //replace this with your own ssid
const char* password = "mugo2020"; //replace this with your password

int ledPin = 13;


void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPing,LOW);

  //connect to wifi
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
}

void loop() {
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(100);
}
