int Flame_Sensor = A0;  // A0에 센서 연결
int Sensor_val;  // 센서 ADC값 저장 변수
int G_LED = 6;  // 초록 LED
int R_LED = 7;  // 빨간 LED
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼통신 속도설정
  pinMode(G_LED, OUTPUT);  // 초록 LED 출력설정
  pinMode(R_LED, OUTPUT);  // 빨간 LED 출력설정
}
/* 불이 켜지면 녹색 LED가 적색으로 바뀐다. */
void loop()  // 무한 루프
{
  Sensor_val = analogRead(Flame_Sensor);  // 센서 값을 읽어와서 Sensor_val에 넣는다
  if (Sensor_val <= 800)  // 만약 센서 값이 800보다 작거나 같으면
  {
    digitalWrite(R_LED, HIGH);  // 빨간 LED ON
    digitalWrite(G_LED, LOW);  // 초록 LED OFF
  }
  else  // 센서 값이 800보다 작지 않으면
  {
    digitalWrite(R_LED, LOW);  // 빨간 LED OFF
    digitalWrite(G_LED, HIGH);  // 초록 LED ON
  }
}

