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
  Serial.print(ledLevel); 
  //delay(1000);
  
  //val =  constrain(val, 500, 200);
  //int ledLevel = map(val, 500, 200, 255, 0); // the variable, min sense, max sense, max output, min output

  //Serial.println(analogRead(sensePin));
  //analogWrite(ledPin, ledLevel);
  /*
  delay(200);
  
  if(val > 500)
  {
   delay(1000);

    for (ledLevel;ledLevel < 255;ledLevel = ledLevel + 21){
      analogWrite(ledPin,ledLevel);
      delay(50);
    }
  }
  else
  {

    
    for (ledLevel;ledLevel >= 0;ledLevel = ledLevel - 21){
      analogWrite(ledPin,ledLevel);
      delay(50);
    }
  }*/
  if (val > 500)
  {
    if (ledLevel >= 0) 
    {
      while(ledLevel <= 255)
      {
        ledLevel += 5;
        analogWrite(ledPin,ledLevel);
        delay(50);
      }
    }
    //ledLevel = 255;
  }
  else{
    
    //if (ledLevel <= 255) 
    //{
      while(ledLevel >= 0)
      {
        ledLevel -= 5;
        analogWrite(ledPin,ledLevel);
        delay(50);
      }
   // }
    //ledLevel = 0;
  }
}
  
