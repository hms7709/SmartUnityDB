int Sensor_Pin = 7;  // 센서 입력 핀
int Sensor_LED = 13;  // 기울기 센서에 내장 되어 있는 LED 핀
int _7ColorLED = 3;  // 7색 LED 핀
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼통신 설정
  pinMode(Sensor_Pin, INPUT_PULLUP);  // 센서 핀을 입력으로 하고 풀 업으로 설정한다.
  pinMode(Sensor_LED, OUTPUT);
  pinMode(_7ColorLED, OUTPUT);
}
/* 기울기 센서를 기울이면 7색 LED가 ON된다. */
void loop()  // 무한루프
{
  if (LOW == digitalRead(Sensor_Pin))  // 만약 입력 받은 센서 값이 LOW이면
  {
    digitalWrite(Sensor_LED, HIGH);  // 센서 LED ON
    digitalWrite(_7ColorLED, LOW);  // 7색 LED OFF
    delay(300);  // 채터링 방지용 딜레이 0.3초
  }
  else
  {
    digitalWrite(_7ColorLED, HIGH);  // 7색 LED ON
    digitalWrite(Sensor_LED, LOW);  // 센서 LED OFF
  }
}

