int S = A0;  // 센서 입력 핀
int R = 4;  // LED 빨간색 출력 핀
int G = 3;  // LED 초록색 출력 핀
int B = 2;  // LED 파란색 출력 핀
void setup()  // 초기화
{
  pinMode(R, OUTPUT);  // LED 빨간색 출력설정
  pinMode(G, OUTPUT);  // LED 초록색 출력설정
  pinMode(B, OUTPUT);  // LED 파란색 출력설정
}
/* 자석을 가까이 대면 LED가 녹색으로 변한다. */
void loop()  // 무한루프
{
  if (analogRead(S) <= 200)  // 만약 센서 값이 200보다 작거나 같으면
  {
    digitalWrite(R, HIGH);  // 빨간 LED ON
    digitalWrite(G, LOW);  // 초록 LED OFF
    digitalWrite(B, LOW);  // 파란 LED OFF
  }
  else  // 센서 값이 200보다 크면
  {
    digitalWrite(R, LOW);  // 빨간 LED OFF
    digitalWrite(G, HIGH);  // 초록 LED ON
    digitalWrite(B, HIGH);  // 파란 LED ON
  }
  delay(100);  // 0.1초 지연
}

