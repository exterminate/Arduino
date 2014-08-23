int sensePin = 0;
int led = 9;
int brightness = 0;
int fadeAmount = 0;
 
void setup()
{
  analogReference(DEFAULT);//isn't necessary
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
 
 
void loop()
{
  Serial.println(analogRead(sensePin));
  int val = analogRead(sensePin);
  if (val < 900)
  {
    if(brightness != 255)
    {
      brightness = 0;
      for(brightness = 0; brightness <= 255; brightness += 5)
      {
        analogWrite(led,brightness);
        delay(50);
      }
      brightness = 255;
      analogWrite(led,brightness);
    }
  }
  else
  {
    brightness = 0;
    analogWrite(led,brightness);
  }
  delay(1000);
}
