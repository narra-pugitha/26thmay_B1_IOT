void setup() {
 
 pinMode(9,OUTPUT);
}

void loop() {
 tone(9,500);
 delay(2000);
 noTone(9);
 delay(2000);
 tone(9,1000);
 delay(5000);
 noTone(9);
 delay(5000);
 tone(9,1500);
 delay(8000);
 noTone(9);
 delay(8000);
 
 
}
