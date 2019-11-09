#include <SoftwareSerial.h>    //블루투스 시리얼 통신 라이브러리 추가
SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)

int Green = 5;
int Yellow = 7;
int Red = 9;    //led 핀 설정

void setup() {
  BTSerial.begin(9600); //블루투스 통신 시작
  pinMode(Green, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT); 
}

void loop() {
  if(BTSerial.available())        //값이 들어오면
  {
    char bt;                     //제어할 변수 bt선언
    bt = BTSerial.read();        //들어온 값을 bt에 저장
    if(bt == 'c')                //bt가 a면
      digitalWrite(Green, HIGH); //초록불 ON
    if(bt == 'j')
      digitalWrite(Yellow, HIGH);
    if(bt == 'a')
      digitalWrite(Red, HIGH);
    if(bt == 'd')
      digitalWrite(Green, LOW);
    if(bt == 'q')
      digitalWrite(Yellow, LOW);
    if(bt == 'w')
      digitalWrite(Red, LOW);
  }
}
