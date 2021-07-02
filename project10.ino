#include <LiquidCrystal.h>// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
#include <Servo.h> //includes the servo library

Servo myservo1;
Servo myservo2;

int ir1 = 2;
int ir2 = 4;

int Total_slots = 5;
int Space;


void setup() {
pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
  
myservo1.attach(3);
myservo2.attach(6);
myservo1.write(100);

lcd.begin(16, 2);  
lcd.setCursor (0,0);
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     System     ");
delay (500);
lcd.clear();
lcd.setCursor (0,0);
lcd.print("Total Slots:5");
lcd.setCursor (0,1);
lcd.print("Slots empty:5");
  

Space = Total_slots;
}

void loop(){ 

if(digitalRead (ir1) == HIGH )
{
if(Space>0)
{
myservo1.write(100);
delay(1000);
myservo1.write(0);
Space = Space-1;
lcd.setCursor (0,0);
lcd.print("Total Slots: ");
lcd.print(Total_slots);

lcd.setCursor (0,1);
lcd.print("Space left: ");
lcd.print(Space);

}

}
else if(Space==0)
{
lcd.setCursor (0,0);
lcd.print(" Sorry no Space ");  
lcd.setCursor (0,1);
lcd.print("    Available    "); 


}
 if(digitalRead(ir2)==HIGH and Space>=0)
{
  
  myservo2.write(100);
delay(1000);
myservo2.write(0);
Space = Space+1;
lcd.clear();
lcd.setCursor (0,0);
lcd.print("Total Slots: ");
lcd.print(Total_slots);

lcd.setCursor (0,1);
lcd.print("Space left: ");
lcd.print(Space);


}

}
