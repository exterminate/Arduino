/*#include <Servo.h>

Servo myservo;
int butOne = 7;
int butTwo = 8;
int val;
int right = 0;
int left = 0;

void setup()
{
  myservo.attach(9);
  pinMode(butOne,INPUT);
  pinMode(butTwo,INPUT);  
}

void loop()
{
  left = digitalRead(butOne);
  right = digitalRead(butTwo);
  if(left == HIGH)
  {
    val += 10;    
  }
  if(right == HIGH)
  {
    val -= 10;    
  }  
  
  myservo.write(val);
}*/
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
