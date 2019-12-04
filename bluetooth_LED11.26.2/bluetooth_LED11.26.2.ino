#include <Servo.h>
#include <SoftwareSerial.h> //블루투스 시리얼 통신 라이브러리 추가

SoftwareSerial BTSerial(2, 3); //블루투스 설정 BTSerial(Tx, Rx)
Servo servo;      //Servo 클래스로 servo객체 생성
  // 각도를 조절할 변수 value

byte buffer[1024]; // 데이터를 수신 받을 버퍼
int bufferPosition; // 버퍼에 데이타를 저장할 때 기록할 위치
int value = 0;  
int room1 = 4;
int room2 = 5; 
int room3 = 6; 
int room4 = 7; 
int room5 = 12;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600); //블루투스 통신 시작
  pinMode(room1, OUTPUT);
  pinMode(room2, OUTPUT);
  pinMode(room3, OUTPUT);
  pinMode(room4, OUTPUT);
  pinMode(room5, OUTPUT);
  servo.attach(10);     //맴버함수인 attach : 핀 설정
  bufferPosition = 0; // 버퍼 위치 초기화
}

void loop() {

   if(BTSerial.available())       
  {
    byte data = BTSerial.read();
    Serial.write(data);
    buffer[bufferPosition++] = data;
    if(data == 'a')        
    digitalWrite(room1, HIGH);
    if(data == 'A')
    digitalWrite(room1, LOW);
    if(data == 'b' )
    digitalWrite(room2, HIGH);
    if(data == 'B' )
    digitalWrite(room2, LOW); 
    if(data == 'c' )   
    digitalWrite(room3, HIGH);
    if(data == 'C' )          
    digitalWrite(room3, LOW); 
   if(data == 'd' )
    digitalWrite(room4, HIGH); 
   if(data == 'D' )
   digitalWrite(room4, LOW);
   if(data == 'e')
    servo.write(90);              //각도를 30도 증가시킨다.
   if(data == 'E')
    servo.write(0);
   
   
     
  }
}

 
