void setup() {
  pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
 int ldr = analogRead(A0);
 Serial.println(ldr);
 if(ldr<40)
{
  digitalWrite(13,HIGH); 
}
else
{
  digitalWrite(13,LOW);
}
}
