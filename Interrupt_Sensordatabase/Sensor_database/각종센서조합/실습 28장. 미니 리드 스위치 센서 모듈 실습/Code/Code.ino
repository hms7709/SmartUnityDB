int R = 5;  // 빨간색 LED핀 
int G = 6;  // 초록색 LED핀
int B = 7;  // 파란색 LED핀
int mReed = 2;  // 리드 스위치 핀
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼 통신 초기화
  pinMode(R, OUTPUT);  // 빨간색 LED 출력 설정
  pinMode(G, OUTPUT);  // 초록색 LED 출력 설정
  pinMode(B, OUTPUT);  // 파란색 LED 출력 설정
  pinMode(mReed, INPUT_PULLUP);  // 리드 스위치 풀업 입력 설정
}
/* 자석을 가까이 하면 LED의 색상을 변화한다. */
void loop()  // 무한루프
{
  if (digitalRead(mReed))  // 센서가 감지되면
  {
    digitalWrite(R, LOW);  // 빨간 LED OFF
    digitalWrite(G, HIGH);  // 초록 LED ON
    digitalWrite(B, LOW);  // 파란 LED OFF
  }
  else  // 센서가 감지되지 않으면
  {
    digitalWrite(R, LOW);  // 빨간 LED OFF
    digitalWrite(G, LOW);  // 초록 LED OFF
    digitalWrite(B, HIGH);  // 파란 LED ON
  }
  delay(100);  // 0.1초 지연
}

