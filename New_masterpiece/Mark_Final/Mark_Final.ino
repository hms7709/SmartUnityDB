#include <Servo.h>
#include "pitches.h"
#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

Servo pianoservo;
int misterymotor = 7;

int pushbutton = 2;
int frontdoor = 5;
int bedroomdoor = 6;
int Tx = 10;
int Rx = 11;
int cds = A0;
int flame = A1;
int fenceLED = 22;
int yardLED = 23;
int bedroomLED[] = {24, 25, 26};
int restroomLED[] = {27, 28, 29};
int kitchenLED[] = {30, 31, 32};
int buzzer = 33;

SoftwareSerial BTSerial(Tx, Rx);
Servo frontservo;
Servo bedroomservo;
DHT DHTsensor(4, DHT11);
LiquidCrystal_I2C mylcd (0x27, 16, 2);  // 거실 LCD
byte buffer[1024];
int pushstate = 0;
int bufferPosition = 0;
unsigned long intervals[] = {2000 ,3000, 4000, 5000};
unsigned long last[] = {0, 0, 0, 0};

void setup() {
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(flame, INPUT);
  pinMode(cds, INPUT);
  pinMode(fenceLED, OUTPUT);
  pinMode(yardLED, OUTPUT);
  pinMode(bedroomLED[0], OUTPUT);
  pinMode(bedroomLED[1], OUTPUT);
  pinMode(bedroomLED[2], OUTPUT);
  pinMode(restroomLED[0], OUTPUT);
  pinMode(restroomLED[1], OUTPUT);
  pinMode(restroomLED[2], OUTPUT);
  pinMode(kitchenLED[0], OUTPUT);
  pinMode(kitchenLED[1], OUTPUT);
  pinMode(kitchenLED[2], OUTPUT);
  pinMode(buzzer, OUTPUT);
  frontservo.attach(frontdoor);
  bedroomservo.attach(bedroomdoor);
  pianoservo.attach(misterymotor);
  pianoservo.write(0);
  DHTsensor.begin();
  mylcd.init();
  mylcd.backlight();
  attachInterrupt(digitalPinToInterrupt(2), isr, FALLING);
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
}

void loop() {

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

   if(now - last[2] >= intervals[2])
   {
       last[2] = now;
       Task2();
   }

   if(now - last[3] >= intervals[3])
   {
       last[3] = now;
       Task3();
   }
   
  if (BTSerial.available()) {
      byte data = BTSerial.read();
      Serial.write(data);
      buffer[bufferPosition++] = data;

      if (data == 'a') // 주방
      {
         analogWrite(kitchenLED[0], 255);
         analogWrite(kitchenLED[1], 0);
         analogWrite(kitchenLED[2], 0);
      }

      else if (data == 'A')
      {
         analogWrite(kitchenLED[0], 255);
         analogWrite(kitchenLED[1], 255);
         analogWrite(kitchenLED[2], 255);
      }

      else if (data == 'b') // 화장실
      {
         analogWrite(restroomLED[0], 255);
         analogWrite(restroomLED[1], 0);
         analogWrite(restroomLED[2], 255);
      }

      else if (data == 'B') 
      {
         analogWrite(restroomLED[0], 255);
         analogWrite(restroomLED[1], 255);
         analogWrite(restroomLED[2], 255);
      }

      else if (data == 'c') // 울타리 LED ON
      {
         digitalWrite(fenceLED, HIGH);
      }

      else if (data == 'C')  // 울타리 LED OFF
      {    
         digitalWrite(fenceLED, LOW);
      }
  
      else if (data == 'd')  // 현관등 LED ON
      {
         digitalWrite(yardLED, HIGH);
      }
       
      else if (data == 'D')  // 현관등 LED OFF
      {
         digitalWrite(yardLED, LOW);
      }

      else if (data == 'e')   // 정문 Open
      {
         frontservo.write(90);         
      }
      
      else if (data == 'E')  // 정문 Close
      {
         frontservo.write(0);
      }

      else if (data == 'f')  // 안방
      {
         analogWrite(bedroomLED[0], 0);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 0);
      }

      else if (data == 'F')  // 안방
      {
         analogWrite(bedroomLED[0], 255);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 255);
      }
      else if (data == 'g')  // 수면 모드
      {
         analogWrite(bedroomLED[0], 0);
         analogWrite(bedroomLED[1], 255);
         analogWrite(bedroomLED[2], 0);
         analogWrite(kitchenLED[0], 0);
         analogWrite(kitchenLED[1], 255);
         analogWrite(kitchenLED[2], 0);
         analogWrite(restroomLED[0], 0);
         analogWrite(restroomLED[1], 255);
         analogWrite(restroomLED[2], 0);
      }
      else if (data == 'G')  // 일반 모드
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
      }
   }
}

void Task0() {
  mylcd.setCursor(0, 0);
  mylcd.print("Welcome People  ");
  mylcd.setCursor(0, 1);
  mylcd.print("This is I-HOME      ");
}

void Task1() {
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
}

void Task2() {
   int cdsvalue = analogRead(cds);
   Serial.print("CDS : ");
   Serial.println(cdsvalue);
   mylcd.setCursor(0, 0);
   mylcd.print("CDS VALUE      ");
   mylcd.setCursor(0, 1);
   mylcd.print(cdsvalue);
   mylcd.print("           ");
   
  if (cdsvalue < 200)
  {
    bedroomservo.write(0);
  }
  else
  {
    bedroomservo.write(80);
  }
}

void Task3(){
   int flamevalue = analogRead(flame);
   Serial.print("flame : ");
   Serial.println(flamevalue);
   mylcd.setCursor(0, 0);
   mylcd.print("FLAME VALUE    ");
   mylcd.setCursor(0, 1);
   mylcd.print(flamevalue);
   mylcd.print("           ");
   
  if (flamevalue < 800)
  {
    tone(buzzer, 956); 
  }
  else
  {
    noTone(buzzer);
  }
}

void isr() {
   pushstate++;
   if (pushstate == 1)
   {
     frontservo.write(80);
   }
   else if (pushstate == 2)
   {    
     frontservo.write(0);
     pushstate = 0; 
   }
}
