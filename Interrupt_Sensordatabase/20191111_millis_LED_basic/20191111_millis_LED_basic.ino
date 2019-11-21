unsigned long time = millis();

void setup() 
{
  pinMode(13, OUTPUT);
}

void loop() 
{
  if(time + 1000 < millis())
  {
    digitalWrite(13, HIGH);
  }

  if(time + 2000 < millis())
  {
    time = millis();
    digitalWrite(13, LOW);
  }
}

/* loop 안에서 delay를 기다리지 않고 자유롭게 작동 
스위치 입력을 받거나, 시리얼 모니터링을 하거나 여러가지를
할 수 있다. 실제로 저 time이라는 변수를 여러 개 써서 각
시간마다 특정 동작이 되도록 몇 개를 짤 수 있다.
이렇게 하면 아두이노로 동시에 여러가지 작업을 할 수 있다.*/
