#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);    // 거실 LCD
Servo myservo;                            // 정문 (안 됨)
Servo myservo2;                           // 안방, 블라인드 문
int pushbutton = 2;                       // 아케이드 스위치
int relay = 3;                            // 릴레이(화장실) - 안 됨
int cds = A0;                             // 조도센서
int servoPin = 5;                         // 정문
int servoPin2 = 6;                        // 안방, 블라인드 문
int flame = A1;                           // 불꽃센서
int Tx = 10;                              // 전송
int Rx = 11;                              // 수신
int Liquid_level = 0;                     // 수위센서 데이터 초기화
SoftwareSerial BTSerial(Tx, Rx);          
DHT DHTsensor (4, DHT11);                 // 온도센서 설정
unsigned long intervals[] = {3000, 3000, 4000, 4500, 1000, 1500, 2000, 2500, 3000, 3500, 3000, 3000000, 4000};
// 1: 온도센서 2: 조도센서 3: 불꽃센서 4~10: 주방 LED(삼색 제어) 11~12: 릴레이 제어 13: 수위센서
// 무드등은 다 안 됨!
unsigned long last[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int buzzer = 7;     // 불꽃센서 부저
int humiLED = 8;    // 습도표시 LED
int notouch_water = 12;  // 비접촉 수위센서
int yardLED[]  = {22, 23, 24, 25, 26, 27, 28, 29}; 
int fenceLED[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43};
byte buffer[1024];
int bufferPosition;

void setup() {
  pinMode(yardLED[0], OUTPUT);
  pinMode(yardLED[1], OUTPUT);
  pinMode(yardLED[2], OUTPUT);
  pinMode(yardLED[3], OUTPUT);
  pinMode(yardLED[4], OUTPUT);
  pinMode(yardLED[5], OUTPUT);
  pinMode(yardLED[6], OUTPUT);
  pinMode(yardLED[7], OUTPUT);
  pinMode(fenceLED[0], OUTPUT);
  pinMode(fenceLED[1], OUTPUT);
  pinMode(fenceLED[2], OUTPUT);
  pinMode(fenceLED[3], OUTPUT);
  pinMode(fenceLED[4], OUTPUT);
  pinMode(fenceLED[5], OUTPUT);
  pinMode(fenceLED[6], OUTPUT);
  pinMode(fenceLED[7], OUTPUT);
  pinMode(fenceLED[8], OUTPUT);
  pinMode(fenceLED[9], OUTPUT);
  pinMode(fenceLED[10], OUTPUT);
  pinMode(fenceLED[11], OUTPUT);
  pinMode(pushbutton, INPUT_PULLUP);    // 정문 스위치
  pinMode(relay, OUTPUT);               // 릴레이(화장실 욕조)
  pinMode(buzzer, OUTPUT);              // 주방 부저
  pinMode(humiLED, OUTPUT);             // 습도 60% LED
  pinMode(notouch_water, INPUT);       // 비접촉 수위센서
  myservo.attach(servoPin);
  myservo2.attach(servoPin2);
  mylcd.init();
  mylcd.backlight();
  DHTsensor.begin();
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
}

void loop() {
  unsigned long now = millis();
  if(now - last[0] >= intervals[0])
  {
     last[0] = now;
     firstTask();
  }

  if(now - last[1] >= intervals[1])
  {
     last[1] = now;
     secondTask();
  }

  if(now - last[2] >= intervals[2])
  {
     last[2] = now;
     thirdTask();
  }

  if(now - last[12] >= intervals[12])
  {
     last[12] = now;
     Task13();
  }

  if (BTSerial.available()) {
    byte data = BTSerial.read();     // 수신 받은 데이터 저장
    Serial.write(BTSerial.read());   // 블루투스측 내용을 시리얼 모니터에 출력
    buffer[bufferPosition++] = data; // 수신 받은 데이터를 버퍼에 저장

    if (data == 'a') // 주방 무드등 ON(1)
    {
      if(now - last[3] >= intervals[3])
      {
        last[3] = now;
        fourTask();
      }

      if(now - last[4] >= intervals[4])
      {
        last[4] = now;
        fiveTask();
      }

      if(now - last[5] >= intervals[5])
      {
        last[5] = now;
        sixTask();
      }

      if(now - last[6] >= intervals[6])
      {
        last[6] = now;
        sevenTask();
      }

      if(now - last[7] >= intervals[7])
      {
        last[7] = now;
        eightTask();
      }

      if(now - last[8] >= intervals[8])
      {
        last[8] = now;
        nineTask();
      }

      if(now - last[9] >= intervals[9])
      {
        last[9] = now;
        tenTask();
      }
    }

    if (data == 'A') // 주방 무드등 OFF
    {
      analogWrite(44, 255);
      analogWrite(45, 255);    
      analogWrite(46, 255);
    }
    
    if (data == 'b') // 화장실 무드등 ON(2)
    {
       analogWrite(47, 0);
       analogWrite(48, 0);    
       analogWrite(49, 0);
    }

    if (data == 'B') // 화장실 무드등 OFF
    {
       analogWrite(47, 255);
       analogWrite(48, 255);    
       analogWrite(49, 255);
    }
    
    if (data == 'c') // 울타리 LED ON
    {
      digitalWrite(fenceLED[0], HIGH);
      digitalWrite(fenceLED[1], HIGH);
      digitalWrite(fenceLED[2], HIGH);
      digitalWrite(fenceLED[3], HIGH);
      digitalWrite(fenceLED[4], HIGH);
      digitalWrite(fenceLED[5], HIGH);
      digitalWrite(fenceLED[6], HIGH);
      digitalWrite(fenceLED[7], HIGH);
      digitalWrite(fenceLED[8], HIGH);
      digitalWrite(fenceLED[9], HIGH);
      digitalWrite(fenceLED[10], HIGH);
      digitalWrite(fenceLED[11], HIGH);
    }
    
    if (data == 'C') // 울타리 LED OFF
    {
      digitalWrite(fenceLED[0], LOW);
      digitalWrite(fenceLED[1], LOW);
      digitalWrite(fenceLED[2], LOW);
      digitalWrite(fenceLED[3], LOW);
      digitalWrite(fenceLED[4], LOW);
      digitalWrite(fenceLED[5], LOW);
      digitalWrite(fenceLED[6], LOW);
      digitalWrite(fenceLED[7], LOW);
      digitalWrite(fenceLED[8], LOW);
      digitalWrite(fenceLED[9], LOW);
      digitalWrite(fenceLED[10], LOW);
      digitalWrite(fenceLED[11], LOW);
    }
    
    if (data == 'd') // 현관등 LED ON
    {
      digitalWrite(yardLED[0], HIGH);
      digitalWrite(yardLED[1], HIGH);
      digitalWrite(yardLED[2], HIGH);
      digitalWrite(yardLED[3], HIGH);
      digitalWrite(yardLED[4], HIGH);
      digitalWrite(yardLED[5], HIGH);
      digitalWrite(yardLED[6], HIGH);
      digitalWrite(yardLED[7], HIGH);
    }
    
    if (data == 'D') // 현관등 LED OFF
    {
      digitalWrite(yardLED[0], LOW);
      digitalWrite(yardLED[1], LOW);
      digitalWrite(yardLED[2], LOW);
      digitalWrite(yardLED[3], LOW);
      digitalWrite(yardLED[4], LOW);
      digitalWrite(yardLED[5], LOW);
      digitalWrite(yardLED[6], LOW);
      digitalWrite(yardLED[7], LOW);
    }
    
    if (data == 'e') // 정문 ON
    {
      myservo.write(179);
    }
    
    if (data == 'E') // 정문 OFF
    {
      myservo.write(0);
    }

    if (data == 'f') // 안방 무드등 ON(3)
    {
      analogWrite(13, 0);
      analogWrite(30, 255);    
      analogWrite(31, 0);
    }

    if (data == 'F') // 안방 무드등 OFF
    {
      analogWrite(13, 255);
      analogWrite(30, 255);    
      analogWrite(31, 255);
    }

    if (data == 'h') // 욕조물 제어
    {
      if(now - last[10] >= intervals[10])
      {
        last[10] = now;
        Task11();
      }

      if(now - last[11] >= intervals[11])
      {
        last[11] = now;
        Task12();
      }
    }
  }

  if (digitalRead(pushbutton) == LOW)
  {
    myservo.write(179); 
  }
  
  else
  {
    myservo.write(0);
  }
}

void firstTask() {
    float humi = DHTsensor.readHumidity();
    float temp = DHTsensor.readTemperature();
    Serial.print("Temp : ");
    Serial.print(temp);
    Serial.print("C ");
    Serial.print("humi : ");
    Serial.print(humi);
    Serial.println("%");
    mylcd.setCursor(0, 0);
    mylcd.print("Temp = ");
    mylcd.print(temp);
    mylcd.print(" C");
    mylcd.setCursor(0, 1);
    mylcd.print("Humi = ");
    mylcd.print(humi);
    mylcd.print( "%");
    
    if (humi > 60)
    {
      digitalWrite(humiLED, HIGH);
    }
    else
    {
      digitalWrite(humiLED, LOW);
    }
}

void secondTask(){
  int cdsvalue = analogRead(cds);
  Serial.print("cds : ");
  Serial.println(cdsvalue);
  if (cdsvalue < 100)
  {
    myservo2.write(179);
  }
  else
  {
    myservo2.write(0);
  }
}

void thirdTask(){
  int flamevalue = analogRead(flame);
  Serial.print("flame : ");
  Serial.println(flamevalue);
  if (flamevalue < 100)
  {
    tone(buzzer, 956); 
  }
  else
  {
    noTone(buzzer);
  }
}

void fourTask(){
     analogWrite(44, 0);
     analogWrite(45, 255);
     analogWrite(46, 255);  
}

void fiveTask(){
     analogWrite(9, 255);
     analogWrite(10, 0);
     analogWrite(11, 255); 
}

void sixTask(){
     analogWrite(44, 255);
     analogWrite(45, 255);
     analogWrite(46, 0); 
}

void sevenTask(){
     analogWrite(44, 0);
     analogWrite(45, 0);
     analogWrite(46, 255); 
}

void eightTask(){
     analogWrite(44, 0);
     analogWrite(45, 255);
     analogWrite(46, 0); 
}

void nineTask(){
     analogWrite(44, 255);
     analogWrite(45, 0);
     analogWrite(46, 0); 
}

void tenTask(){
     analogWrite(44, 0);
     analogWrite(45, 0);
     analogWrite(46, 0);
}

void Task11(){
   digitalWrite(relay, HIGH);
}

void Task12(){
   digitalWrite(relay, LOW);
}

void Task13(){
  Liquid_level = digitalRead(12);
  Serial.print("Liquid_level = ");
  Serial.println(Liquid_level, DEC);
}
