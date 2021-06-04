#include<LiquidCrystal.h>
//lcd(rs,en,d4,d5,d6,d7)
LiquidCrystal lcd(12,11,5,4,3,2);
void setup()
{
  pinMode(9,INPUT);
  lcd.begin(16,2);
}

void loop()
{ 
  int button=digitalRead(9);
  if(button==0)
 {
 lcd.setCursor(0,0);
 lcd.print("Good Morning!");
 delay(1000); 
 lcd.clear();
 }
 else
 {
 lcd.setCursor(0,0);
 lcd.print("Good Night!"); 
 }

}
