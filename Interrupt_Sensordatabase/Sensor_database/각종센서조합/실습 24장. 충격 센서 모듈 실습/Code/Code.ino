int Sensor_Pin= 7; //센서 입력핀
void setup()  // 초기화
{
 Serial.begin(9600); //시리얼통신 설정
 pinMode(Sensor_Pin, INPUT_PULLUP);//센서핀을 입력으로 하고 풀업으로 설정한다.
}
/*센서에 충격이 가해지면 시리얼 모니터에 'Shock' 로 뜹니다.*/
void loop()  // 무한루프
{
 if (LOW == digitalRead(Sensor_Pin))  // 만약 입력받은 센서 값이 LOW이면
 {
  Serial.println("Shock");  // 시리얼 모니터로 "Shock" 출력
  delay(300);  //채터링 방지용 딜레이 0.3초
 }
}
