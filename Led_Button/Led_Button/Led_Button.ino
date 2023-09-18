#define nutnhan 22
#define den 23

void setup() 
{  
  pinMode(nutnhan, INPUT_PULLUP);
  pinMode(den, OUTPUT);
}

void loop() {
 if( digitalRead(nutnhan) == LOW)
   {
      digitalWrite(den,HIGH);
   }
 else
   {
      digitalWrite(den,LOW);
   }
}
