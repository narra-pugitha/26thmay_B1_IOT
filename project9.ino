#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
int temp;
int cel;

const int maxspeed = 255,midspeed = 150,lowspeed = 90;
void setup() {
  pinMode(temp, INPUT);
pinMode(6,OUTPUT);
  lcd.begin(16, 2);

}

void loop() {
  temp = analogRead(A0);
  cel = temp * 0.48828125;
  if (cel < 15) {
  
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
    lcd.setCursor(12,0);
    lcd.print(cel);
    lcd.setCursor(0,1);
    lcd.print("Fanspeed = low"); 
    analogWrite(6,lowspeed);
  }



  else if(cel>15&&cel<30){
  
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
     lcd.setCursor(12,0);
    lcd.print(cel);
      lcd.setCursor(0,1);
    lcd.print("Fanspeed = mid"); 
    analogWrite(6,midspeed);
    delay(1000);
    lcd.clear();
  }

else if(cel>30)
{
  
    lcd.setCursor(0, 0);
    lcd.print("Temperature:");
     lcd.setCursor(12,0);
    lcd.print(cel);
    lcd.setCursor(0,1);
    lcd.print("Fanspeed = max"); 
    analogWrite(6,maxspeed);
    delay(1000);
    lcd.clear();
}
}
