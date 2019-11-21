unsigned long previousMillis = 0;
// Interval을 5초로 지정
long interval = 5000;

int led = 13;
int sw = 5;

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() 
{
  // 현재 시간 측정
  unsigned long currentMillis = millis();
  char c = Serial.read();

  if(digitalRead(sw) == LOW)
  {
    previousMillis = currentMillis;
    digitalWrite(led, HIGH);
  }
  // a라는 글자를 입력한 경우 Hello문구 출력
  else
  {
    if(c = 'a')
    {
      Serial.println("Hello");
    }
  }

  // LED가 켜진지 5초 뒤에 LED를 끈다
  if(currentMillis - previousMillis > interval)
  {
    digitalWrite(led, LOW);
  }
}

/* 시간의 차이를 이용하여 delay()를 구현하는데 매 루프마다 Millis()를
 *  사용하여 현재 시간을 측정. 그 후에 특정 이벤트가 발생하면 그 이벤트의
 *  발생시간을 측정하고 변수에 저장.(previousMillis) 이벤트의 발생시간과
 *  현재 시간을 비교하여 특정 시간 이상이 되면 수행해야 할 명령어를 실행.
 *  
 *  1. 매 loop마다 현재 시간을 측정하여 currentMillis에 저장.
 *  2. 스위치를 누르면 previousMillis라는 변수에 스위치를 누른시간을
 *     체크해서 저장.
 *  3. 매 loop마다 현재 시간(currentMillis)을 체크해서 스위치를 누른시간(previousMillis)이
 *     5000(5초)가 되면 LED를 끈다.
 *  4. delay()가 존재하지 않기 때문에 스위치를 눌러 LED가 켜지고 꺼지는 동안에도
 *     시리얼 모니터 출력은 제대로 동작.
 *     
 *  
 *  
 *  
 *  
 *  
 */
