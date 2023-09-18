#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define den 19

const char* ssid     = "LUN 1";
const char* password = "Xomtro179";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "1.asia.pool.ntp.org", 7*60*60); //VN giờ UTC+7 : thong so thu3 la giay 

const int giomo = 01;
const int phutmo = 58;

void setup() {
  pinMode(den, OUTPUT);
  digitalWrite(den, LOW);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println(".");
  }
  Serial.println();7
  Serial.println("Da Ket Noi Wifi.");
  timeClient.begin();
}

void loop() {
  timeClient.update();
  int gio = timeClient.getHours();
  int phut = timeClient.getMinutes();
  int giay = timeClient.getSeconds();
  Serial.print("Bay gio la: ");
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
  if (gio == giomo && phut==phutmo){
    digitalWrite(den, HIGH);
//    Serial.println("Den ON");
  }
}
