#include<WiFi.h>
const char *ssid = "LUN 1";
const char *password = "Xomtro179";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("connect to AP...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
