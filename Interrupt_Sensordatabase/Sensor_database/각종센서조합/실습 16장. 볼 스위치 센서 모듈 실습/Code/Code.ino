int R = 2;//빨간색 LED 핀
int G = 3;//초록색 LED 핀
int B = 4;//파란색 LED 핀
int ball = 12;//볼스위치 핀
 
// 프로그램 시작 - 초기화 작업
void setup()  // 초기화
{
 Serial.begin(9600); // 시리얼 통신 초기화
 pinMode(R, OUTPUT);  //빨간색 LED 출력설정
 pinMode(G, OUTPUT);  //초록색 LED 출력설정
 pinMode(B, OUTPUT);  //파란색 LED 출력설정
 pinMode(ball, INPUT_PULLUP);  // 볼 스위치 센서 모듈 풀업 입력 설정
}
/*볼스위치를 기우리면 LED의 색이 변한다.*/ 
void loop()  // 무한루프
{
 if(digitalRead(ball)){  //만약 볼스위치가 들어오면
   digitalWrite(R,LOW);  //빨간색 LED OFF
   digitalWrite(G,HIGH);  //초록색 LED ON
   digitalWrite(B,LOW);  //파란색 LED OFF
  }
  else{
   digitalWrite(R,LOW);  //빨간색 LED OFF
   digitalWrite(G,LOW);  //초록색 LED OFF
   digitalWrite(B,HIGH);  //파란색 LED ON
  }
 delay(100);  //0.1초 딜레이
}
