#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Azzt";
const char* password = "khanhdeptrai";

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Connect to AP...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("https://example.com");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(5000); // Delay for 5 seconds before making another request
}
