int lightPin = A0;
int humPin = A1;
int ledPin = 13;
int buzzerPin = 8;

unsigned long checkMillis = 0;  // 각각의 시간간격을 구하기 위해 millis()값을 저장하는 변수를 동작마다 따로 선언해준다.
unsigned long blinkMillis = 0;
unsigned long sendMillis = 0;
int blinkCnt = 0;

boolean ledState = LOW;

int lightValue = 0;
int humValue = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() 
{
  unsigned long curMillis = millis();
  // 100 밀리초 간격으로 조도센서와 습도센서의 값을 읽어옴(아날로그 값을 읽어올 경우 약간의 시간 간격이 있어야 오차가 적음)
  // 조도 센서의 값이 500 이하일 경우 LED를 1초 간격으로 3회 깜빡이기 위해 blinkCnt 변수와 blinkMillis 변수의 값을 저장한다.
  if(curMillis - checkMillis > 100)
  {
    checkMillis = curMillis;
    lightValue = analogRead(lightPin);
    humValue = analogRead(humPin);

    if(lightValue > 500) && (blinkCnt == 0))
    {
      blinkMillis = curMillis;
      blinkCnt = 6; // 3 * 2 = 6
    }
  }
  // 1초 간격으로 습도 센서의 값을 시리얼로 전송한다.
  if(curMillis - sendMillis > 1000)
  {
    sendMillis = curMillis;
    Serial.println(humValue);
  }

  // blinkCnt값이 0보다 크고 조도센서 값이 500 이하여서 blinkCnt 값이 바뀌었고, blinkMillis 값을
  // curMillis 값과 확인하여 1초가 지났을 경우 LED를 켜거나 끈다. blinkCnt의 값을 1씩 감소해서
  // 0이 되면 blinkCnt > 0 조건이 FALSE가 되어 더이상 깜빡이지 않게 된다.
  if((blinkCnt > 0) && (curMillis - blinkMillis > 1000))
  {
    blinkMillis = curMillis;
    blinkCnt--;
    if(ledState == LOW)
    {
      ledState = HIGH);
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      ledState = LOW;
      digitalWrite(ledPin, LOW);
    }
  }
}

void serialEvent()
{
  char c = Serial.read();
  if(c == 'A')
  {
    tone(buzzerPin, 1000, 100);
  }
}
