int Temp_Sensor = A0;  // A0에 센서 연결
int Sensor_val;  // 센서 ADC값 저장 변수
double TempConversion(int v)  // 센서 값을 온도 값으로 변경하는 함수
{
  double Temp;  // 계산에 필요한 double형 변수선언
  Temp = log(10000.0 / (1024.0 / v - 1));  // 계산식에 따른 온도 계산식
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp);
  Temp = Temp - 292.55;  // Temp = (Temp * 9.0) / 5.0 + 32.0;
  return Temp;  // 계산된 값을 반환
}
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼 통신 속도설정
}
/* 온도 값을 시리얼 모니터로 표시한다. */
void loop()  // 무한루프
{
  Sensor_val = analogRead(Temp_Sensor);  // 센서 값을 읽어와서 Sensor_val에 저장
  Serial.print("TEMP : ");  // 시리얼 모니터에 TEMP : 출력
  Serial.println(TempConversion(Sensor_val), DEC);
  // 시리얼 모니터에 온도 값을 10진수로 출력하고 한 줄 내림
  delay(500);  // 0.5초 지연
}

