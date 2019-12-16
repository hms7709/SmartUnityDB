#include <SimpleTimer.h>                     // 타이머 라이브러리
#include <Servo.h>                           // 서보모터 라이브러리
#include "pitches.h"                         // 주파수 헤더파일
#include <SoftwareSerial.h>                  // 블루투스 통신 라이브러리 
#include <DHT.h>                             // DHT11(온습도센서) 라이브러리
#include <DHT_U.h>                           // DHT11(온습도센서) 라이브러리
#include <LiquidCrystal_I2C.h>               // I2C 통신 라이브러리 - Text LCD에 활용

SimpleTimer timer1, timer2;                  // 타이머 라이브러리 변수 설정
int misterymotor = 7;                        // 비밀의 방 모터
int pushbutton = 2;                          // 비상 개폐 스위치 - 프로그램 동작 안 되는 경우
int frontdoor = 5;                           // 정문 모터
int bedroomdoor = 6;                          // 안방 블라인드 창문 모터
int Tx = 10;                                 // HC-06 모듈 Tx
int Rx = 11;                                 // HC-06 모듈 Rx
int notouch_water = 12;                      // 비접촉 수위센서 
int cds = A0;                                // 조도 센서
int flame = A1;                              // 불꽃 센서
int fenceLED = 22;                           // 울타리 LED
int yardLED = 23;                            // 현관 LED
int bedroomLED[] = {24, 25, 26};             // 안방 3색 LED
int restroomLED[] = {27, 28, 29};            // 화장실 3색 LED
int kitchenLED[] = {30, 31, 32};             // 주방 3색 LED
int buzzer = 33;                             // 부저

SoftwareSerial BTSerial(Tx, Rx);             // 블루투스 라이브러리 변수 선언
Servo frontservo;                            // 서보모터 라이브러리 변수 설정(정문)
Servo bedroomservo;                          // 서보모터 라이브러리 변수 설정(안방)
DHT DHTsensor(4, DHT11);                     // DHT11 라이브러리 변수 설정
LiquidCrystal_I2C mylcd (0x27, 16, 2);       // Text LCD 라이브러리 변수 설정 (주소, 열 수, 행 수) 
byte buffer[1024];                           // byte 자료형의 길이가 1024인 버퍼 설정
int ledcount = 0;                            // 인터럽트 실행을 위한 ledcount 변수 선언 및 초기화
int pushstate = 0;                           // 인터럽트 실행을 위한 pushstate(스위치 상태) 변수 선언 및 초기화
int bufferPosition = 0;                      // 버퍼 증가시키기 위한 변수 설정 
unsigned long intervals[] = {2000 ,4000, 6000, 8000, 10000};          // 타이머 인터럽트를 위한 시간 간격 조정
unsigned long last[] = {0, 0, 0, 0, 0};                               // 타이머 인터럽트를 위한 시간 간격 조정  
int Liquid_level = 0;                                                 // 비접촉 수위센서 상태 초기화

void setup() {
  pinMode(pushbutton, INPUT_PULLUP);                                  // 스위치 핀                  
  pinMode(flame, INPUT);                                              // 불꽃 센서 핀
  pinMode(cds, INPUT);                                                // 조도 센서 핀
  pinMode(notouch_water, INPUT);                                      // 비접촉 수위 센서 핀
  pinMode(fenceLED, OUTPUT);                                          // 울타리 LED 핀
  pinMode(yardLED, OUTPUT);                                           // 현관등 LED 핀
  pinMode(bedroomLED[0], OUTPUT);                                     // 안방 3색 LED(Red)
  pinMode(bedroomLED[1], OUTPUT);                                     // 안방 3색 LED(Green)
  pinMode(bedroomLED[2], OUTPUT);                                     // 안방 3색 LED(Blue)
  pinMode(restroomLED[0], OUTPUT);                                    // 화장실 3색 LED(Red)
  pinMode(restroomLED[1], OUTPUT);                                    // 화장실 3색 LED(Green)
  pinMode(restroomLED[2], OUTPUT);                                    // 화장실 3색 LED(Blue)
  pinMode(kitchenLED[0], OUTPUT);                                     // 주방 3색 LED(Red)
  pinMode(kitchenLED[1], OUTPUT);                                     // 주방 3색 LED(Green)
  pinMode(kitchenLED[2], OUTPUT);                                     // 주방 3색 LED(Blue)
  pinMode(buzzer, OUTPUT);                                            // 부저 
  frontservo.attach(frontdoor);                                       // 정문 모터 설정
  bedroomservo.attach(bedroomdoor);                                   // 안방 블라인드 모터 설정
  DHTsensor.begin();                                                  // DHT11 온습도센서 초기화
  mylcd.init();                                                       // Text LCD 초기화
  mylcd.backlight();                                                  // Text LCD 백라이트 설정
  attachInterrupt(digitalPinToInterrupt(2), isr, FALLING);            // 인터럽트 핀 설정
  Serial.begin(9600);                                                 // 시리얼 통신 속도 9600bps 설정
  BTSerial.begin(9600);                                               // 블루투스 통신 속도 9600bps 설정
  bufferPosition = 0;                                                 // bufferPosition 변수 선언 및 초기화
}

void loop() {

   unsigned long now = millis();              // millis() 함수를 활용한 타이머 인터럽트 

   if(now - last[0] >= intervals[0])          // 첫 번째 작업
   {
       last[0] = now;
       Task0();
   }
      
   if(now - last[1] >= intervals[1])          // 두 번째 작업
   {
       last[1] = now;
       Task1();
   }

   if(now - last[2] >= intervals[2])          // 세 번째 작업
   {
       last[2] = now;
       Task2();
   }

   if(now - last[3] >= intervals[3])          // 네 번째 작업
   {
       last[3] = now;
       Task3();
   }

   if(now - last[4] >= intervals[4])          // 다섯 번째 작업
   {
       last[4] = now;
       Task4();
   }
   
   if (BTSerial.available()) {                // 아두이노와 안드로이드 간의 블루투스 통신 
      byte data = BTSerial.read();
      Serial.write(data);
      buffer[bufferPosition++] = data;

      if (data == 'a')              // 주방 3색 LED ON
      {
         analogWrite(kitchenLED[0], 255);
         analogWrite(kitchenLED[1], 0);
         analogWrite(kitchenLED[2], 0);
      }

      else if (data == 'A')         // 주방 3색 LED OFF
      {
         analogWrite(kitchenLED[0], 255);
         analogWrite(kitchenLED[1], 255);
         analogWrite(kitchenLED[2], 255);
      }

      else if (data == 'b')         // 화장실 3색 LED ON
      {
         analogWrite(restroomLED[0], 255);
         analogWrite(restroomLED[1], 0);
         analogWrite(restroomLED[2], 255);
      }

      else if (data == 'B')         // 화장실 3색 LED OFF
      {
         analogWrite(restroomLED[0], 255);
         analogWrite(restroomLED[1], 255);
         analogWrite(restroomLED[2], 255);
      }

      else if (data == 'c')         // 울타리 LED ON
      {  
         digitalWrite(fenceLED, HIGH);
      }

      else if (data == 'C')         // 울타리 LED OFF
      {    
         digitalWrite(fenceLED, LOW);
      }
  
      else if (data == 'd')         // 현관등 LED ON
      {
         digitalWrite(yardLED, HIGH);
      }
       
      else if (data == 'D')         // 현관등 LED OFF
      {
         digitalWrite(yardLED, LOW);
      }

      else if (data == 'e')         // 정문 Open
      {
         frontservo.write(90);         
      }
      
      else if (data == 'E')         // 정문 Close
      {
         frontservo.write(0);
      }

      else if (data == 'f')         // 안방 3색 LED ON
      {
         analogWrite(bedroomLED[0], 0);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 0);
      }

      else if (data == 'F')         // 안방 3색 LED OFF
      {
         analogWrite(bedroomLED[0], 255);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 255);
      }
      else if (data == 'g')         // 수면 모드
      {
         analogWrite(kitchenLED[0], 255);
         analogWrite(kitchenLED[1], 255);
         analogWrite(kitchenLED[2], 255);
         analogWrite(restroomLED[0], 255);
         analogWrite(restroomLED[1], 255);
         analogWrite(restroomLED[2], 255);
         analogWrite(bedroomLED[0], 255);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 255);
         digitalWrite(fenceLED, LOW);
         digitalWrite(yardLED, LOW);
      }
      else if (data == 'G')          // 일반 모드
      {
         analogWrite(kitchenLED[0], 0);
         analogWrite(kitchenLED[1], 0);
         analogWrite(kitchenLED[2], 0);
         analogWrite(restroomLED[0], 0);
         analogWrite(restroomLED[1], 0);
         analogWrite(restroomLED[2], 0);
         analogWrite(bedroomLED[0], 0);
         analogWrite(bedroomLED[1], 0);
         analogWrite(bedroomLED[2], 0);
         digitalWrite(fenceLED, HIGH);
         digitalWrite(yardLED, HIGH);
      }
      else if (data == 'h')               // 전시 모드
      {
         ledcount++;                      // ledcount 증가
         led_display();                   // led_display() 함수 실행
      }
   }
   timer1.run();                          // 변수 timer1 실행
   timer2.run();                          // 변수 timer2 실행
}

void Task0() {
  mylcd.setCursor(0, 0);                  // 0열 0행 부터      
  mylcd.print("Welcome People  ");        // Welcome People 출력
  mylcd.setCursor(0, 1);                  // 0열 1행 부터
  mylcd.print("This is I-HOME       ");   // This is I-Home 출력
}

void Task1() {
   float humi = DHTsensor.readHumidity();         // 실수값으로 온도 읽어들이기
   float temp = DHTsensor.readTemperature();      // 실수값으로 습도 읽어들이기
   Serial.print("Temp : ");
   Serial.print(temp);                            // 온도값 출력
   Serial.print("C ");
   Serial.print("humi : ");
   Serial.print(humi);                            // 습도값 출력
   Serial.println("%");
   mylcd.setCursor(0, 0);                         // 0행 0열부터
   mylcd.print("Temp : ");
   mylcd.print(temp);                             // Text LCD에 온도값 출력
   mylcd.print(" C");
   mylcd.setCursor(0, 1);                         // 0행 1열부터
   mylcd.print("Humi : ");
   mylcd.print(humi);                             // Text LCD에 습도값 출력
   mylcd.print(" %");
}

void Task2() {
   int cdsvalue = analogRead(cds);    // 조도센서값 읽어들임
   Serial.print("CDS : ");                    
   Serial.println(cdsvalue);          // 조도센서값 출력
   mylcd.setCursor(0, 0);             // 0행 0열부터
   mylcd.print("CDS VALUE       ");
   mylcd.setCursor(0, 1);             // 0행 1열부터
   mylcd.print(cdsvalue);             // Text LCD에 조도센서값 출력
   mylcd.print("           ");
   
  if (cdsvalue < 200)         // 조도센서값이 200보다 작으면 
  {
    bedroomservo.write(0);    // 블라인드 Close
  }
  else                        // 그렇지 않을 때는
  {
    bedroomservo.write(80);   // 블라인드 Open
  }
}

void Task3(){
   int flamevalue = analogRead(flame);  // 불꽃센서값 읽어들임
   Serial.print("flame : ");
   Serial.println(flamevalue);          // 불꽃센서값 출력
   mylcd.setCursor(0, 0);               // 0행 0열부터
   mylcd.print("FLAME VALUE     ");
   mylcd.setCursor(0, 1);               // 0행 1열부터
   mylcd.print(flamevalue);
   mylcd.print("           ");
   
  if (flamevalue < 800)       // 불꽃센서값이 800보다 작으면
  {
    tone(buzzer, 956);        // 부저에서 음이 발생
  }
  else                        // 그렇지 않을 때는
  {
    noTone(buzzer);           // 무음 처리
  }
}

void Task4(){
   Liquid_level = digitalRead(12);          // 디지털 값으로 읽어들임
   Serial.print("Liquid_level = ");   
   Serial.println(Liquid_level, DEC);   
   mylcd.setCursor(0, 0);                   // 0행 0열부터
   mylcd.print("WATER VALUE    ");
   mylcd.setCursor(0, 1);                   // 0행 1열부터
   mylcd.print(Liquid_level);               // Text LCD에 비접촉수위센서값 출력
   mylcd.print("               ");
}

void LED_ON(){ 
    digitalWrite(fenceLED, HIGH);
    digitalWrite(yardLED, HIGH);
}

void LED_OFF(){
    digitalWrite(fenceLED, LOW);
    digitalWrite(yardLED, LOW);
}

void led_display() {       // 전시 모드 실행 함수   
    if (ledcount == 1)
    {
          timer1.setTimeout(1000, LED_ON);
          timer2.setTimeout(3000, LED_OFF);
          timer1.setTimeout(5000, LED_ON);
          timer2.setTimeout(7000, LED_OFF);
          timer1.setTimeout(9000, LED_ON);
          timer2.setTimeout(11000, LED_OFF);
          timer1.setTimeout(13000, LED_ON);
          timer2.setTimeout(15000, LED_OFF);
          timer1.setTimeout(17000, LED_ON);
          timer2.setTimeout(19000, LED_OFF);
          timer1.setTimeout(21000, LED_ON);
          timer2.setTimeout(23000, LED_OFF);
          timer1.setTimeout(25000, LED_ON);
          timer2.setTimeout(27000, LED_OFF);
          timer1.setTimeout(29000, LED_ON);
          timer2.setTimeout(31000, LED_OFF);
          timer1.setTimeout(33000, LED_ON);
          timer2.setTimeout(35000, LED_OFF);
          timer1.setTimeout(37000, LED_ON);
          timer2.setTimeout(39000, LED_OFF);   
   }       
}

void isr() {
   pushstate++;                   
   switch(pushstate)
   {
      case 1:
        frontservo.write(80);     // 정문 열림
        break;
      case 2:
        frontservo.write(0);      // 정문 닫힘
        pushstate = 0;
        break;       
   }

   
 /*  if (pushstate == 1)            // 만약에 pushstate값이 1이면
   {
     frontservo.write(80);        // 정문 열림
   }
   else if (pushstate == 2)       // 만약에 pushstate 값이 2이면
   {    
     frontservo.write(0);         // 정문 닫힘
     pushstate = 0;
   } */
}
