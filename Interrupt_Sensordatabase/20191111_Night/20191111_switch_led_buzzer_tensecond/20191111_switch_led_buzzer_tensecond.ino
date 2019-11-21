unsigned long ledPreMillis = 0;
unsigned long buzzerPreMillis = 0;
unsigned long offPreMillis = 0;

int ledState = LOW;

void setup() 
{
  
}
/*1. 스위치가 눌렸을 때
 *2. 1초 간격으로 LED를 깜빡이고
 *3. 3초 간격으로 부저가 울리게 한다.
 *  
 */

void loop() 
{
  unsigned long curMillis = millis();
  
  if(bPushSwitch)
  {
    ledPreMillis = buzzerPreMillis = offPreMillis = curMillis;
  }

  if(ledPreMillis > 0) && (curMillis - ledPreMillis > 1000))
  {
    ledPreMillis = curMillis;
    if(ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }

  if(buzzerPreMillis > 0) && (curMillis - buzzerPreMillis > 3000))
  {
    buzzerPreMillis = curMillis;
    tone(buzzerPin, 1000, 500);
  }
  if((offPreMillis > 0) && (curMillis - offPreMillis > 10000))
  {
    ledPreMillis = buzzerPreMillis = offPreMillis = 0;
  }
}
