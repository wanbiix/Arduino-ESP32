#include <DHT.h>
#define cb 33
const int DHTTYPE = DHT11;

DHT dht(cb, DHTTYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float doam = dht.readHumidity();
  float doC = dht.readTemperature();
  float doF = dht.readTemperature(true);
  //ktra cb co hoat dogn khong
  if (isnan(doam)||isnan(doC)||isnan(doF)){
    Serial.println("Khong co gia tri tra ve tu cam bien");
    delay(500);
    return;
  }
  Serial.print("Do am: ");
  Serial.print(doam);
  Serial.print("      ");
  Serial.print("Nhiet do C %: ");
  Serial.println(doC);
  delay(500);
  
}
