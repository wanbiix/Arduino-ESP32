
#define led 2
#define button 12
#define cb 36

void setup() {
  Serial.begin(9600);
  pinMode(cb, INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP); 
}

void loop() {
  int lightval = digitalRead(cb);
  Serial.println(lightval);
  
  if (lightval==HIGH){
    digitalWrite(led, HIGH);    
  }else digitalWrite(led, LOW);
  
  if(digitalRead(button)==LOW){
    digitalWrite(led, !digitalRead(led));
    delay(200);
  }
}
