int sensePin = 0;
int ledPin = 9;
int ledLevel = 0;

void setup()
{
  analogReference(DEFAULT);//isn't necessary
  pinMode(ledPin,OUTPUT);
  //Serial.begin(9600);
}


void loop()
{

  int val = analogRead(sensePin);
  //delay(1000);
  
  //val =  constrain(val, 500, 200);
  //int ledLevel = map(val, 500, 200, 255, 0); // the variable, min sense, max sense, max output, min output

  //Serial.println(analogRead(sensePin));
  //analogWrite(ledPin, ledLevel);
  delay(200);
  
  if(val > 500)
  {
   delay(1000);
    /*while(ledLevel <= 255)
    {
      
      analogWrite(ledPin, ledLevel);
      delay(50);
      
      ledLevel += 21;
    } */
    for (ledLevel;ledLevel < 255;ledLevel = ledLevel + 21){
      analogWrite(ledPin,ledLevel);
      delay(50);
    }
  }
  else
  {
    /*
    while(ledLevel >= 0)
    {
      delay(50);
      analogWrite(ledPin,ledLevel);
      ledLevel -= 21;
    }*/
    
    for (ledLevel;ledLevel >= 0;ledLevel = ledLevel - 21){
      analogWrite(ledPin,ledLevel);
      delay(50);
    }
  }
}
  
