#include<Keypad.h>
String notice="";

char keys[4][3]={
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char rows[4]={6,7,8,9};
char columns[3]={3,4,5};

Keypad keypad=Keypad(makeKeymap(keys),rows,columns,4,3);

void setup(){
 Serial.begin(9600);
 Serial.println("School Notice board");
   Serial.println("Press 1 to 6 key for notice display");
}

void scrollNotice(){
  unsigned char len=notice.length();
  Serial.print(notice);
  delay(800);
  for(int i=-1;i>=-1*(len-16);i--){
  
    Serial.print(notice);
    delay(200);
  }
  delay(800);
}

void notice1(){
 
  Serial.println("NOTICE 1");
  Serial.println("All students stand in line");
    Serial.println("Press 1 to 6 key for other notice");
}

void notice2(){

  Serial.println("NOTICE 2");
  Serial.println("Don't make noise");
  Serial.println("Press 1 to 6 key for other notice");
}

void notice3(){
  
    Serial.println("NOTICE 3");
    Serial.println("Please maintain silence");
    Serial.println("Press 1 to 6 key for other notice");
}

void notice4(){
   Serial.println("NOTICE 4");
    Serial.println("Tomorrow is a holiday");
  Serial.println("Press 1 to 6 key for other notice");
}

void notice5(){
    Serial.println("NOTICE 5");
  Serial.println("All of you submit your assignment");
   Serial.println("Press 1 to 6 key for other notice");
}

void notice6(){
   Serial.println("NOTICE 6");
    Serial.println("Dont run on the stairs");
    Serial.println("Press 1 to 6 key for other notice");
  
}

void invalidInput(){

   Serial.println("Invalid entry");
 
    Serial.println("Press 1 to 6 key for notice");
  delay(800);
}

void displayNotice(){
  char k=keypad.waitForKey();
  if(k=='1') notice1();
  else if(k=='2') notice2();
  else if(k=='3') notice3();
  else if(k=='4') notice4();
  else if(k=='5') notice5();
  else if(k=='6') notice6();
  else invalidInput();
}

void loop() {
  displayNotice();
}
