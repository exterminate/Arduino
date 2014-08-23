#include <Servo.h>

Servo myservo;
int potpin = 0;//*
int val;
int noisePin = 4;//*
int butOne = 7;
int butTwo = 8;
int right = 10;
int left = 0;
int redled = 2;
int greenled = 3;


void setup()
{
  myservo.attach(9);
  pinMode(butOne,INPUT);
  pinMode(butTwo,INPUT);  
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);  
  Serial.begin(9600);
  
   val = map(val, 0, 1023, left, right);
}
void loop()
{
  digitalWrite(redled,LOW);
  digitalWrite(greenled,LOW);
  //left = digitalRead(butOne);
 // right = digitalRead(butTwo);
 
  if(digitalRead(butOne) == HIGH && val < 170)
  {
    val += 10; 
    digitalWrite(redled,HIGH);   
  }
  if(digitalRead(butTwo) == HIGH && val > 0)
  {
    val -= 10;    
    digitalWrite(greenled,HIGH);
  }  
  
  Serial.print(val);
  //val = analogRead(potpin);
  //val = map(val, 0, 1023, 0, 178);
  myservo.write(val);
  
  
  
  delay(15);
}
