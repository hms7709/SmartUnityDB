int Sensor_Pin = 2;  // 센서 입력 핀
int LED_R = 9;  // 빨간 LED 핀
int LED_G = 8;  // 초록 LED 핀
void setup()  // 초기화
{
  pinMode(Sensor_Pin, INPUT);  // 센서 입력 설정
  pinMode(LED_R, OUTPUT);  // 빨간색 LED 출력 설정
  pinMode(LED_G, OUTPUT);  // 초록색 LED 출력 설정
}
/* 센서가 검은 선 위에 올라가 있으면 LED의 색이 녹색으로 변화한다. */
void loop()  // 무한루프
{
  if (LOW == digitalRead(Sensor_Pin))  // 센서 입력이 LOW가 들어오면
  {
    digitalWrite(LED_G, LOW);  // 초록색 LED OFF
    digitalWrite(LED_R, HIGH);  // 빨간색 LED ON
  }
  else  // 센서 입력이 LOW가 들어오지 않으면
  {
    digitalWrite(LED_R, LOW);  // 빨간색 LED OFF
    digitalWrite(LED_G, HIGH);  // 초록색 LED ON
  }
  delay(100);  // 0.1초 지연
}

