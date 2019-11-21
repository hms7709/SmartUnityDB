int S = A0; //센서입력핀
int R = 2;  //LED 빨간색 출력핀
int G = 3;  //LED 초록색 출력핀
int B = 4;  //LED 파란색 출력핀
 
void setup()  // 초기화
{
 Serial.begin(9600); // 시리얼 통신 설정
 pinMode(R, OUTPUT);  //LED 빨간색 출력설정
 pinMode(G, OUTPUT);  //LED 초록색 출력설정
 pinMode(B, OUTPUT);  //LED 파란색 출력설정
}
/* 자석을 가까이 해서 N극일때 적색 S극일때 청색으로 변한다.*/
void loop()  // 무한루프
{
  Serial.println(analogRead(S));  //시리얼 모니터를 통해 센서값을 출력한다.
 if(analogRead(S)>=600){  //만약 센서의 값이 600보다 크거나 같으면
   digitalWrite(R,HIGH);  // 빨강 LED ON
   digitalWrite(G,LOW);  // 초록 LED OFF
   digitalWrite(B,LOW);  // 파란 LED OFF
  }
  else if(analogRead(S)<=400){  //만약 센서의 값이 400보다 작거나 같으면
   digitalWrite(R,LOW);  // 빨강 LED OFF
   digitalWrite(G,LOW);  // 초록 LED OFF
   digitalWrite(B,HIGH);  // 파란 LED ON
  }
  else{  //센서값이 401~599사이의 값이면
   digitalWrite(R,LOW);  // 빨간 LED OFF
   digitalWrite(G,HIGH);  // 초록 LED ON
   digitalWrite(B,LOW);  // 파란 LED OFF
  }
 delay(100);// 0.1초 지연
}
