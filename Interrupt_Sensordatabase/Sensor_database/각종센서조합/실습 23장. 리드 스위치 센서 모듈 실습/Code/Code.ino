int R = 2;//빨간색 LED 핀
int G = 3;//초록색 LED 핀
int B = 4;//파란색 LED 핀
int reed = 12;  //리드 스위치 핀
// 프로그램 시작 - 초기화 작업
void setup()  // 초기화
{
 Serial.begin(9600); // 시리얼 통신 초기화
 pinMode(R, OUTPUT); //빨간색 LED 출력 설정
 pinMode(G, OUTPUT); //초록색 LED 출력 설정
 pinMode(B, OUTPUT); //파란색 LED 출력 설정
 pinMode(reed, INPUT_PULLUP); //리드 스위치 풀업 입력 설정
}
/*자석을 가까이 하면 LED의 색이 변화한다.*/
void loop()  // 무한루프
{
 if(digitalRead(reed)){  // 리드스위치가 켜지면
   digitalWrite(R,LOW);  // 빨간 LED OFF
   digitalWrite(G,HIGH);  // 초록 LED ON
   digitalWrite(B,LOW);  // 파란 LED OFF
  }
  else{  // 리드스위치가 꺼지면
   digitalWrite(R,LOW);  // 빨간 LED OFF
   digitalWrite(G,LOW);  // 초록 LED OFF
   digitalWrite(B,HIGH);  // 파란 LED ON
  }
 delay(100);//0.1초 지연
}
