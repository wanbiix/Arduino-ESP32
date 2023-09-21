#define A0 32
//#define D0 36

int value, real_value;

unsigned long hientai = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT_PULLUP);
//  pinMode(D0, INPUT_PULLUP);

}

void loop() {
  for(int i=0; i<=9; i++){
    real_value += analogRead(A0);  
  }
  value = real_value/10;
  real_value = 0;
  int percent = map(value, 0, 4095, 0, 100);
  percent = 100 - percent;
  if(millis()- hientai > 2000){
    Serial.print("Gia tri Analog: ");
    Serial.print(value);
    Serial.print("    ");
//    Serial.print("Gia tri Digital: ");
//    Serial.print(digitalRead(D0));
//    Serial.print("    ");
    Serial.print("Do am %: ");
    Serial.println(percent);
    Serial.print(analogRead(A0));
    hientai = millis();
  }
}
