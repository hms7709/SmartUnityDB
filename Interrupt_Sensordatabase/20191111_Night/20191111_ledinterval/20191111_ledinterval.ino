/* 두 개 이상의 시작 조건에 각각의 동작(시간 간격이 다른)이
 *  필요한 경우
 */

unsigned long ledPreMillis = 0;
int ledState = LOW;
int ledInterVal;

void setup() 
{
 
}

void loop() 
{
  unsigned long curMillis = millis();
  int lightValue = analogRead(A0);
  
  if(lightValue < 200)
  {
    ledPreMillis = curMillis;
    ledInterVal = 500;
  }
  else if(lightValue < 500)
  {
    ledPreMillis = curMillis;
    ledInterval = 1000;
  }
  else
  {
    ledPreMillis = 0;
  }
}
