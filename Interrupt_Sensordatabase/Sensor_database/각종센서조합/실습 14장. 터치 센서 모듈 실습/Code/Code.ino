int Sensor_Pin = 7; //센서핀
int Buzzer = 8;    //부저핀
 
// 프로그램 시작 - 초기화 작업
void setup()
{
 pinMode(Sensor_Pin, INPUT);  //센서 입력 설정
 pinMode(Buzzer, OUTPUT);    //부저 출력 설정
}
/*
터치센서가 감지되면 부져가 울린다.
*/
void loop()
{
 if (LOW == digitalRead(Sensor_Pin)) //만약 센서값이 LOW이면
 {
   digitalWrite(Buzzer,LOW);  //부저를 OFF한다.
 }
 else  //만약 센서값이 LOW가 아니면
 {
   digitalWrite(Buzzer,HIGH);  //부저를 ON한다.
 }
 delay(100);  //0.1초 딜레이
}
 
