int ledPin = 13;
int swPin = 2;
boolean bLedOn = false;
boolean bSwOn = false;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);

  digitalWrite(ledPin, LOW);
}

void loop() 
{
  if(digitalRead(swPin) == LOW)
  {
    if(bSwOn == false)
    {
      bSwOn == true;  
      if(bLedOn == false)
      {
        digitalWrite(ledPin, HIGH);
        bLedOn = true;
      }
      else
      {
        digitalWrite(ledPin, LOW);
        bLedOn = false;
      }
    }
  }
