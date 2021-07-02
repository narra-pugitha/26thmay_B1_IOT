#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

const byte rows=4;
const byte cols=3;
 
char key[rows][cols]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[rows]={0,1,2,3};
byte colPins[cols]={4,5,6};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="1947";
int currentposition=0;

Servo myservo;
int pos=0; // position of servo motor
LiquidCrystal lcd(12,11,10,9,8,7); 
 
 
void setup()
{
 
displayscreen();
//Serial.begin(9600);
myservo.attach(13); //Servo motor connection
 
lcd.begin(16,2);
 
}
 
void loop()
{
if( currentposition==0)
{
displayscreen();
 
}
int l ;
char code=keypad.getKey();
if(code!=NO_KEY)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("PASSWORD:");
lcd.setCursor(7,1);
for(l=0;l<=currentposition;++l)
{
 
lcd.print("*");
//keypress();
}
 
if (code==password[currentposition])
{
++currentposition;
if(currentposition==4)
{
 
unlockdoor();
currentposition=0;
 
}
 
}

 
else
{
incorrect();
currentposition=0;
 
}
}
}
 
//------------------ Function 1- OPEN THE DOOR--------------//
 
void unlockdoor()
{
  lcd.clear();
delay(900);
lcd.setCursor(1,0);
lcd.print("Access Granted");
lcd.setCursor(4,1);
lcd.println("WELCOME!!");

delay(1000);
for(pos = 180; pos>=0; pos-=5) // open the door
{
myservo.write(pos); 
delay(5); 
}
 
 
counterbeep();
 
delay(1000);
 
for(pos = 0; pos <= 180; pos +=5) // close the door
{ // in steps of 1 degree
myservo.write(pos); 
delay(15);
 
 
currentposition=0;
 
lcd.clear();
displayscreen();
 
}
}
 
//--------------------Function 2- Wrong code--------------//
 
void incorrect()
{
delay(500);
lcd.clear();
lcd.setCursor(1,0);
lcd.print("CODE");
lcd.setCursor(6,0);
lcd.print("INCORRECT");
lcd.setCursor(4,1);
lcd.println("GET AWAY!!!");

delay(1000);
lcd.clear();
displayscreen();
}


//------------Function 3 - DISPLAY FUNCTION--------------------//
void displayscreen()
{
 
lcd.setCursor(0,0);
lcd.println("*ENTER THE CODE*");
lcd.setCursor(1 ,1);
 
lcd.println("TO OPEN DOOR!!");
}


 
//--------------Function 4 - Count down------------------//
void counterbeep()
{
delay(500);
 
 
lcd.clear();
 
lcd.println("GET IN WITHIN:::");
for(int i=5;i>=0;i--)
{
  lcd.setCursor(4,1);
  lcd.print(i);
  delay(300);
}

delay(500);
lcd.clear();
lcd.setCursor(2,0);
lcd.print("RE-LOCKING");
delay(500);

lcd.clear();
lcd.setCursor(4,0);
lcd.print("LOCKED!");
delay(500);
}
