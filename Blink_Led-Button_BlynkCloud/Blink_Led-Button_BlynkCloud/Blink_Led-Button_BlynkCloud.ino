#define BLYNK_TEMPLATE_ID "TMPL69Pj0BRaO"
#define BLYNK_TEMPLATE_NAME "BlinkLedD23"
#define BLYNK_AUTH_TOKEN "dr3NwvmkWDEXf1zgAiBXmdiezQ6UfYV6"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
const char *ssid = "LUN 1";
const char *password = "Xomtro179";

#define led 23
#define nutnhan 22
boolean trangthai = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(nutnhan, INPUT_PULLUP);
  digitalWrite(led, LOW);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
}

BLYNK_WRITE(V1){
  int p = param.asInt();
  digitalWrite(led, p);
}

void loop() {
  Blynk.run();
  
  if(digitalRead(nutnhan) == LOW){
    if(trangthai == HIGH){
      digitalWrite(led,!digitalRead(led));
      Blynk.virtualWrite(V1, digitalRead(led));
      trangthai = LOW;
      delay(200); 
    }
  }
  else{
    trangthai = HIGH;
  }
}



//BLYNK_WRITE(V1){
//  int p = param.asInt();
//  digitalWrite(nutnhan, p);
//  if (digitalRead(nutnhan) == LOW ){
//    digitalWrite(led, HIGH);
//    Blynk.virtualWrite(V0,HIGH);
//  }
//  else{
//    digitalWrite(led, LOW);
//    Blynk.virtualWrite(V0,LOW);
//  }
//}
