int Tap = 12;  // Tap센서 연결핀
// 프로그램 시작 - 초기화 작업
void setup()  // 초기화
{
 Serial.begin(9600);  // 시리얼 통신 초기화
 pinMode(Tap, INPUT_PULLUP);  // 센서를 입력 풀업으로 설정
}
/*센서가 측정이 되면 시리얼 모니터에 표시한다.*/
void loop()  // 무한루프
{
 if(!digitalRead(Tap)){     //만약 센서가 입력이 되면
   Serial.println("Tap");  //시리얼 모니터에 "Tap" 출력
   delay(100);  //0.1초 지연
  }
}
