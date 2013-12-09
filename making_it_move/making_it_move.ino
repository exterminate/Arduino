#include <Servo.h>

Servo myservo;
int potpin = 0;
int val;
int noisePin = 4;

void setup()
{
  myservo.attach(9);
}
void loop()
{
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 178);
  myservo.write(val);
  
  
  
  delay(15);
}
