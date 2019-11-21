#include <IRremote.h>  // 적외선 송수신을 하기 위해서 IRremote 라이브러리를 사용한다.
IRsend irsend;
void setup(){  // 초기화
  Serial.begin(9600);  //시리얼 통신 설정
}
/*적외선 송신으로 '968' '8618'을 송신한다.*/
void loop(){
  irsend.sendSony(0x968, 32);  //IR을 통해 968을 송신
  delay(1000);                 //1초 지연
  irsend.sendSony(0x8618, 32); //IR을 통해 8618을 송신
  delay(1000);                 //1초 지연
}
