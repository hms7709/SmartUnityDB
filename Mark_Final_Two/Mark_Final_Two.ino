#include <Servo.h>         // 서보 모터 라이브러리
#include "pitches.h"       // 주파수 헤더 파일
#include <Key.h>           // 키패드 헤더 파일
#include <Keypad.h>        // 키패드 헤더 파일

int relay = 3;             // 릴레이 핀 설정
int tru = 0;               // '참', '거짓' 판별 변수 선언
int count = 0;             // 카운트 변수 선언
char PW[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};     // 키패드 버튼 배열 
const byte ROWS = 4;       // 4행
const byte COLS = 4;       // 4열
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};
int mistery_buzzer = 8;    // 부저 

char keys[ROWS][COLS] = 
   {{ '1', '2', '3', 'A' }, 
   { '4', '5', '6', 'B' },
   { '7', '8', '9', 'C' }, 
   { '*', '0', '#', 'D' }};

Servo myservo;
int servoPin = 7;
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);    // 키패드 변수 설정

unsigned long intervals[] = {5000, 10000};    // 타이머 인터럽트를 위한 시간 간격 설정 (5초 동안 relay on, 5초 동안 relay off)
unsigned long last[] = {0, 0};                // 타이머 인터럽트를 위한 시간 간격 설정

void setup()
{
  Serial.begin(9600);
  pinMode (mistery_buzzer, OUTPUT);
  myservo.attach(servoPin);
  myservo.write(90);                          // 시작과 동시에 서보모터를 90도로 회전
  pinMode(relay, OUTPUT);
}

void loop()
{
  char key = mykeypad.getKey();
  
  if (key)
  {
    Serial.println(key);
    if (key == PW[0])                   // '1'을 눌렀을 때
    {
      tone (mistery_buzzer, 262);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[1])
    {
      tone (mistery_buzzer, 294);       // '2'를 눌렀을 때
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++; 
    }

    if (key == PW[2])                   // '3'을 눌렀을 때
    {
      tone (mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++; 
    }
    
    if (key == PW[3])                   // 'A'를 눌렀을 때
    {
      tone (mistery_buzzer, 349);
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[4])                   // '4'를 눌렀을 때
    {
      tone (mistery_buzzer, 392);
      analogWrite(8, 0);
      analogWrite(9, 0);
      analogWrite(10, 255);
      count++;
      tru++;
    }

    if (key == PW[5])                   // '5'를 눌렀을 때   
    {
      tone(mistery_buzzer, 440);
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[6])                   // '6'을 눌렀을 때 
    {
      tone(mistery_buzzer, 494);
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 0);
      count++;
      tru++; 
    }

    if (key == PW[7])                   // 'B'을 눌렀을 때 
    {
      tone(mistery_buzzer, 523);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 0);
      myservo.write(0);
      Serial.println("open the door"); 
      count++;
      tru++;
    }

    if (key == PW[8])                  // '7'을 눌렀을 때
    {
      tone(mistery_buzzer, 392);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[9])                  // '8'을 눌렀을 때
    {
      tone(mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[10])                 // '9'를 눌렀을 때
    {
      tone(mistery_buzzer, 294);
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[11])                 // 'C'를 눌렀을 때
    {
      tone(mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

     if (key == PW[12])                // '*'를 눌렀을 때
    {
      tone(mistery_buzzer, 262);
      myservo.write(90);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[13])                 // '0'를 눌렀을 때
    {
      noTone(mistery_buzzer);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 255);
      tru = 0;
      count = 0;
    }
    
    else if (key == '#')               // '#'을 눌렀을 때
    {
       replay();
    }
  }

   unsigned long now = millis();       // millis() 함수를 활용한 타이머 인터럽트
      
   if(now - last[0] >= intervals[0])   // 첫 번째 작업
   {
       last[0] = now;
       Task0();
   }

   if(now - last[1] >= intervals[1])   // 두 번째 작업
   {
       last[1] = now;
       Task1();
   }
}

void Task0()
{
   digitalWrite(relay, HIGH);         // relay on
}

void Task1()
{
   digitalWrite(relay, LOW);          // relay off
}

void replay()  // 리셋 함수
{
  tru = 0;
  count = 0;
  Serial.println("password reset");
}
