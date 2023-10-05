#define BLYNK_TEMPLATE_ID "TMPL6L_IZrTtN"
#define BLYNK_TEMPLATE_NAME "Presentation 03 Assignment"
#define BLYNK_AUTH_TOKEN "88YoD6E0Px5DjsGqT_n2UBsVZQNyeFtE"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#define BLYNK_PRINT Serial
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "LUN 1";
char pass[] = "Xomtro179";

#define cb 33
#define quat 22
const int DHTTYPE = DHT11;
DHT dht(cb, DHTTYPE);
float doC, doam;
unsigned long time_dht = 0;

void cb_dht11(){
  doam = dht.readHumidity();
  doC = dht.readTemperature();
  if (isnan(doam)||isnan(doC)){
    Serial.println("Khong co gia tri tra ve tu cam bien");
    return;
  }
  Serial.print("Temp: " + String(doC, 2) + "°C" + "     ");
  Blynk.virtualWrite(V0, doC);
  Serial.println("Humi: " + String(doam, 1) + "%");
  Blynk.virtualWrite(V1, doam); 
}

BLYNK_WRITE(V2){
  int quat_tt = param.asInt();
  digitalWrite(quat, quat_tt);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
  pinMode(quat, OUTPUT);
  digitalWrite(quat, LOW);
}

void loop() {
  Blynk.run();
  if((millis()-time_dht)>1000){
    cb_dht11();
    time_dht=millis();
  }
}
