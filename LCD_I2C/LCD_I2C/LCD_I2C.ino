#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup()
{
  lcd.begin();                    
  lcd.backlight();
  
}
void loop()
{
  lcd.setCursor(2,0);
  lcd.print("Arduinokit.vn");
  lcd.setCursor(0,1);
  lcd.print("Xin chao cac ban");
  
  delay(1000);
  lcd.clear();
}
