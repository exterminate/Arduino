/*
HC-SR04 Ping distance sensor]
VCC to arduino 5v GND to arduino GND
Echo to Arduino pin 13 Trig to Arduino pin 12
Red POS to Arduino pin 11
Green POS to Arduino pin 10
560 ohm resistor to both LED NEG and GRD power rail
More info at: http://goo.gl/kJ8Gl
Original code improvements to the Ping sketch sourced from Trollmaker.com
Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
*/

#include <Servo.h>

Servo myservo;
int trigPin = 4;
int echoPin = 5;
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;
int val;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  myservo.attach(3);
}

void loop() { 
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance <= 10) {  // This is where the LED On/Off happens
    digitalWrite(led4,HIGH);
  }else digitalWrite(led4,LOW);
    
  if (distance <= 20) {  // This is where the LED On/Off happens
    digitalWrite(led3,HIGH);
  }else digitalWrite(led3,LOW);
  
  if (distance <= 30) {  // This is where the LED On/Off happens
    digitalWrite(led2,HIGH);
  }else digitalWrite(led2,LOW);
  
  if (distance <= 40 ) {  // This is where the LED On/Off happens
    digitalWrite(led1,HIGH);
  }else digitalWrite(led1,LOW);
  
  if (distance > 40 ) {  // This is where the LED On/Off happens
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }

  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  
  val = map(distance, 0, 200, 0, 178);
  myservo.write(val);
  Serial.println(val);
  delay(500);
}

