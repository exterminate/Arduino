
int spd = 100;
int potPin = 0;

void setup()
{
  for(int outpin = 7; outpin < 14; outpin++)
  {
    pinMode(outpin,OUTPUT);
  }
}
void loop()
{
  
 int val = analogRead(potPin); 
 spd = map(val, 0, 1023, 255, 10);
 
 
 for(int strobe = 7; strobe < 13; strobe++)
 {
   digitalWrite(strobe,HIGH);
   delay(spd);
   digitalWrite(strobe,LOW);
 }
 for(int strobe = 13; strobe > 7; strobe--)
 {
   digitalWrite(strobe,HIGH);
   delay(spd);
   digitalWrite(strobe,LOW);
 }
}
