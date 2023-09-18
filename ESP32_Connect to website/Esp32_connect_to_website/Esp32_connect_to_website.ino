#include <WiFi.h>
#include <WiFiClient.h>

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
  WiFiClient client;
    
  // Kết nối tới địa chỉ web HTTP
  if (client.connect("example.com", 80)) {
    Serial.println("Kết nối thành công");
    
    // Gửi yêu cầu HTTP
    Serial.println("GET / HTTP/1.1");
    Serial.println("Host: example.com");
    Serial.println("Connection: close");
    Serial.println();

    // Đọc và in ra nội dung phản hồi
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
    
    client.stop();
  } 
  else {
    Serial.println("Không thể kết nối");
  }
  delay(5000); // Chờ 5 giây trước khi gửi yêu cầu tiếp theo
}
