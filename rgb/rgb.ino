int red = 8;
int green = 9;
int blue = 10;

int buttonState = 0;
int but = 12;

void setup()
{
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT); 
  pinMode(green,OUTPUT);  
  pinMode(but,INPUT); // button
  Serial.begin(9600);
}

void loop()
{
  
  buttonState = digitalRead(but);
  Serial.print(buttonState);
  if(buttonState == HIGH)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW); 
  }
  else
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH); 
    delay(500);  
    
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH); 
    delay(500);  
      
    digitalWrite(blue, LOW);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    delay(500);   

  }
}
