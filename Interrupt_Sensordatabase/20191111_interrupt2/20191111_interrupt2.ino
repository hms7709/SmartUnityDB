int ledPin = 13;
int swPin = 2;
boolean bLedOn = false;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(swPin, INPUT_PULLUP);
  attachInterrupt(0, swInterrupt, FALLING);
  /*swPin의 상태를 확인해서 핀의 상태가 HIGH에서 LOW로 바뀔 때
  swInterrupt() 함수를 자동 호출하도록 설정하는 함수*/
  digitalWrite(ledPin, LOW)
}

void loop()
{
  delay(1000);
}


void swInterrupt()
{
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
