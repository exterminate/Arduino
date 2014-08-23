#include <Servo.h>

int led_1 = 11;
int led_2 = 10;
int led_3 = 9;

void setup(){
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
}

void loop(){
  
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,HIGH);
  digitalWrite(led_3,HIGH);
  delay(1000);
  digitalWrite(led_2,LOW);
  delay(1000);
  digitalWrite(led_3,LOW);  
}
