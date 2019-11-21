int Sensor_Pin = 2;  // 입력 핀
int LED_R = 9;  // 빨간색 LED 핀
int LED_G = 8;  // 초록색 LED 핀
void setup()  // 프로그램 시작 - 초기화 작업
{
  pinMode(Sensor_Pin, INPUT);  // 센서 핀 입력 설정
  pinMode(LED_R, OUTPUT);  // 빨간색 LED 출력 설정
  pinMode(LED_G, OUTPUT);  // 초록색 LED 출력 설정
}
/* 물체가 가까이 오면 LED의 색이 변화한다. */
void loop()  // 무한루프
{
  if (LOW == digitalRead(Sensor_Pin))  // 센서에 LOW 신호가 들어오면
  {
    digitalWrite(LED_G, LOW);  // 초록색 LED OFF
    digitalWrite(LED_R, HIGH);  // 빨간색 LED ON
  }
  else
  {
    digitalWrite(LED_R, LOW);  // 빨간색 LED OFF
    digitalWrite(LED_G, HIGH);  // 초록색 LED ON
  }
  delay(100);  // 0.1초 지연
}

