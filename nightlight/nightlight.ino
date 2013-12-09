int sensePin = 0;
int ledPin = 9;

void setup()
{
  analogReference(DEFAULT);//isn't necessary
  pinMode(ledPin,OUTPUT);
}


void loop()
{

  int val = analogRead(sensePin);
  
  val =  constrain(val,200,500);
  int ledLevel = map(val, 200, 500, 255, 0); // the variable, min sense, max sense, max output, min output

  
  analogWrite(ledPin, ledLevel);
  
  /*
  if(val < 500)
  {
    digitalWrite(ledPin, HIGH); 
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }*/
}
  
