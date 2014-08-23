#include <Servo.h>

Servo myservo;
int led_1 = 11;
int led_2 = 10;
int led_3 = 9;
int trig_Pin = 4;
int echo_Pin = 5;

void setup(){
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  Serial.begin(9600);
  pinMode(trig_Pin, OUTPUT);
  pinMode(echo_Pin, INPUT);
  myservo.attach(13); 
}

void loop(){
  long duration, distance;
  digitalWrite(trig_Pin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig_Pin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trig_Pin, LOW);
  duration = pulseIn(echo_Pin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance < 20){
    myservo.write(175);
    digitalWrite(led_1,HIGH);
    digitalWrite(led_2,HIGH);
    digitalWrite(led_3,HIGH);
    delay(1000);
    digitalWrite(led_1,LOW);
    delay(1000);
    digitalWrite(led_2,LOW);
    delay(1000);
    digitalWrite(led_3,LOW);  
    delay(1000);
    //val = map(distance, 0, 200, 0, 178);
    myservo.write(0);
  }  
}
