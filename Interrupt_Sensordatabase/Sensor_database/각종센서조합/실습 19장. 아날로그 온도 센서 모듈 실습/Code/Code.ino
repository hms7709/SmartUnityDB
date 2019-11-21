int Temp_Sensor = A0;  // A0에 센서 연결
int Sensor_val;  // 센서 ADC값 저장 변수
int G_LED = 6;  // 초록 LED
int R_LED = 7;  // 빨간 LED
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼 통신 속도 설정
  pinMode(G_LED, OUTPUT);  // 초록 LED 출력 설정
  pinMode(R_LED, OUTPUT);  // 빨간 LED 출력 설정
}
/* 온도에 따라 LED의 색이 변화한다. */
void loop()  // 무한루프
{
  Sensor_val = analogRead(Temp_Sensor);  // 센서 값을 읽어와서 Sensor_val에 저장
  if (Sensor_val <= 500)  // 센서 값이 500보다 작거나 같으면
  {
    digitalWrite(R_LED, HIGH);  // 빨간 LED ON
    digitalWrite(G_LED, LOW);  // 초록 LED OFF
  }
  else  // 센서 값이 500보다 작지 않으면
  {
    digitalWrite(R_LED, LOW);  // 빨간 LED OFF
    digitalWrite(G_LED, HIGH);  // 초록 LED ON
  }
}

