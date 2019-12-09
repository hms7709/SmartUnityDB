#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);       // 거실 LCD
Servo myservo;
Servo myservo2;
int pushbutton = 2;
int servoPin = 5;
int servoPin2 = 6;
int cds = A0;
int Tx = 10;
int Rx = 11;
int yardLED[] = {22, 23, 24, 25, 26, 27, 28, 29};
int fenceLED[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
int bedroom[] = {42, 43, 44};
int kitchen[] = {45, 46, 47};
int restroom[] = {48, 49, 50};

SoftwareSerial BTSerial(Tx, Rx);
DHT DHTsensor (4, DHT11);
unsigned long intervals[] = {2000, 2000};
unsigned long last[] = {0, 0};
int humiLED = 8;
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
  pinMode(humiLED, OUTPUT);       // 습도 부저 LED
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(bedroom, OUTPUT);
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
  
   if (digitalRead(pushbutton) == LOW)
   {
     myservo.write(179);
   }
   else
   {
     myservo.write(0);
   }
   
   unsigned long now = millis();  

   if(now - last[0] >= intervals[0])
   {
      last[0] = now;
      Task0();
   }

   if(now - last[1] >= intervals[1])
   {
      last[1] = now;
      Task1();
   }

   if (BTSerial.available()) {
     byte data = BTSerial.read();
     Serial.write(BTSerial.read());
     buffer[bufferPosition++] = data;

     if (data == 'a')           // 주방 LED ON
     {
         analogWrite(kitchen[0], 0);
         analogWrite(kitchen[1], 0);
         analogWrite(kitchen[2], 255);
     }

     else if (data == 'A')      // 주방 LED OFF
     {
          analogWrite(kitchen[0], 255);
          analogWrite(kitchen[1], 255);
          analogWrite(kitchen[2], 255);
     }

     else if (data == 'b')      // 화장실 LED ON
     {
          analogWrite(restroom[0], 255);
          analogWrite(restroom[1], 0);
          analogWrite(restroom[2], 0);
     }

     else if (data == 'B')      // 화장실 LED OFF 
     {
          analogWrite(restroom[0], 255);
          analogWrite(restroom[1], 255);
          analogWrite(restroom[2], 255);
     }
   
     else if (data == 'c') // 울타리 LED ON
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

     else if (data == 'C')  // 울타리 LED OFF
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

     else if (data == 'd')  // 현관등 LED ON
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

     else if (data == 'D')  // 현관등 LED OFF
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

     else if (data == 'e')   // 정문 Open
     {
       myservo.write(179);
     }

     else if (data == 'E')   // 정문 close
     {
       myservo.write(0);
     }

     else if (data == 'f')   // 안방 LED ON (보라색)
     {
        analogWrite(bedroom[0], 0);
        analogWrite(bedroom[1], 255);
        analogWrite(bedroom[2], 0);
     }

     else if (data == 'F')   // 안방 LED OFF
     {
        analogWrite(bedroom[0], 255);
        analogWrite(bedroom[1], 255);
        analogWrite(bedroom[2], 255);
     }

  /* else if (data == 'h')   // 욕조 밸브 열림
     {
       
     }

     else if (data == 'H')   // 욕조 밸브 잠금
     {
       
     } */

      else if (data == '\n')
     {
      buffer[bufferPosition] = '\0';
      bufferPosition = 0;
     }
   }
   if (Serial.available()) {         
    BTSerial.write(Serial.read());
  }
}

void Task0() {
    float humi = DHTsensor.readHumidity();
    float temp = DHTsensor.readTemperature();
    Serial.print("Temp : ");
    Serial.print(temp);
    Serial.print("C ");
    Serial.print("humi : ");
    Serial.print(humi);
    Serial.println("%");
    mylcd.setCursor(0, 0);
    mylcd.print("Temp : ");
    mylcd.print(temp);
    mylcd.print(" C");
    mylcd.setCursor(0, 1);
    mylcd.print("Humi : ");
    mylcd.print(humi);
    mylcd.print(" %");
    
    if (humi < 10)
    {
      digitalWrite(humiLED, HIGH);
    }
    else
    {
      digitalWrite(humiLED, LOW);
    }
}

void Task1() {
  int cdsvalue = analogRead(cds);
  Serial.print("CDS : ");
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
  
