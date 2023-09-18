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

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, password);
//  while (WiFi.status() != WL_CONNECTED);
//  Serial.print("AP IP address: ");
//  Serial.println(WiFi.localIP());
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0){
  int p = param.asInt();
  digitalWrite(led, p);
}
