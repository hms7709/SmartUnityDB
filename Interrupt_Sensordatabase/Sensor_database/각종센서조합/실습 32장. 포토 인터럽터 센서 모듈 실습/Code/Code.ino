int Sensor_Pin = 7; //센서 입력핀
void setup()  // 초기화
{
 Serial.begin(9600); //시리얼통신 설정
 pinMode(Sensor_Pin, INPUT_PULLUP); //센서 풀업 입력 설정
}
/*센서에 물체가 들어가면 IN, 나오면 OUT이 시리얼 모니터로 출력된다.*/
void loop()  // 무한루프
{
 if (HIGH == digitalRead(Sensor_Pin))  // 물체가 감지 되었을 때
 {
   Serial.println("IN");  //시리얼모니터 "IN" 출력
   delay(10);  //10ms 지연
   while(digitalRead(Sensor_Pin));  //센서에 물체가 감지되고 있는동안 대기
   Serial.println("OUT");  //시리얼모니터 "OUT" 출력
   delay(300);  //300ms 지연
 }
}
