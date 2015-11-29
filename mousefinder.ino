/*
trying to see if we have a mouse that comes in under the sink.

if it goes past the distance sensor play a sound

and maybe lights up

*/
#include "pitches.h"

int trigPin = 4;
int echoPin = 5;
int led = 2; /* use the built in one */
int tonePin = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(tonePin, OUTPUT)
  digitalWrite(led,LOW);
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
  if (distance <= 3) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH);
    for(int i = 0; i <= 20; i++) {
      tone(tonePin,440,200);
      tone(tonePin,880,200);
    }
  }
  delay(10);
}
