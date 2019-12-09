#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
Servo frontservo;      // 외부 5v
Servo bedroomservo;    // 외부 5v
LiquidCrystal_I2C mylcd (0x27, 16, 2);       // 거실 LCD
int pushbutton = 2;    // 5v
int frontdoor = 5;     // 외부 5v
int bedroommotor = 6;  // 외부 5v
int cds = A0;          // 아두이노 5V
int flame = A1;        // 아두이노 5V
int Tx = 10;            
int Rx = 11;
SoftwareSerial BTSerial(Tx, Rx);
byte buffer[1024];
DHT DHTsensor(4, DHT11);
int bufferPosition = 0;
volatile int pushstate = 0;
int Liquid_level = 0;
unsigned long intervals[] = {2000, 2000, 2000, 2000};
unsigned long last[] = {0, 0, 0, 0};
int fenceLED = 22;
int yardLED = 23;
int bedLED[] = {24, 25, 26};
int kitchenLED[] = {27, 28, 29};
int buzzer = 30;
//int restroomLED[] = {31, 32, 33};
//int mysteryLED[] = {34, 35, 36};
int notouch_water = 37;

void setup() {
  pinMode(fenceLED, OUTPUT);
  pinMode(yardLED, OUTPUT);
  pinMode(pushbutton, INPUT_PULLUP);
  pinMode(cds, INPUT);
  pinMode(flame, INPUT);
  pinMode(notouch_water, INPUT);
  pinMode(bedLED[0], OUTPUT);
  pinMode(bedLED[1], OUTPUT);
  pinMode(bedLED[2], OUTPUT);
  pinMode(kitchenLED[0], OUTPUT);
  pinMode(kitchenLED[1], OUTPUT);
  pinMode(kitchenLED[2], OUTPUT);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), isr, FALLING);
  frontservo.attach(frontdoor);
  bedroomservo.attach(bedroommotor);
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
  DHTsensor.begin();
  mylcd.init();
  mylcd.backlight();
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
         digitalWrite(kitchenLED[0], LOW);
         digitalWrite(kitchenLED[1], LOW);
         digitalWrite(kitchenLED[2], HIGH);
      }

      else if (data == 'A')
      {
         digitalWrite(kitchenLED[0], HIGH);
         digitalWrite(kitchenLED[1], HIGH);
         digitalWrite(kitchenLED[2], LOW);
      }

      else if (data == 'b') // 화장실
      {
         digitalWrite(restroomLED[0], HIGH);
         digitalWrite(restroomLED[1], LOW);
         digitalWrite(restroomLED[2], HIGH);
      }

      else if (data == 'B') 
      {
         digitalWrite(restroomLED[0], HIGH);
         digitalWrite(restroomLED[1], HIGH);
         digitalWrite(restroomLED[2], HIGH);
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
         frontservo.write(179);         
      }
      
      else if (data == 'E')  // 정문 Close
      {
         frontservo.write(0);
      }

      else if (data == 'f')  // 안방
      {
         digitalWrite(bedLED[0], LOW);
         digitalWrite(bedLED[1], HIGH);
         digitalWrite(bedLED[2], LOW);
      }

      else if (data == 'F')  // 안방
      {
         digitalWrite(bedLED[0], HIGH);
         digitalWrite(bedLED[1], LOW);
         digitalWrite(bedLED[2], HIGH);
      }

      else if (data == 'g') // 빨간색
      {
         digitalWrite(mysteryLED[0], LOW);
         digitalWrite(mysteryLED[1], HIGH);
         digitalWrite(mysteryLED[2], HIGH);
      }

      else if (data == 'h') // 녹색
      {
         digitalWrite(mysteryLED[0], HIGH);
         digitalWrite(mysteryLED[1], LOW);
         digitalWrite(mysteryLED[2], HIGH);
      }

      else if (data == 'i') // 파란색
      {
         digitalWrite(mysteryLED[0], HIGH);
         digitalWrite(mysteryLED[1], HIGH);
         digitalWrite(mysteryLED[2], LOW);
      }
   }
}

void isr() {
   pushstate++;
   if (pushstate == 1)
   {
     frontservo.write(179);
   }
   else if (pushstate == 2)
   {    
     frontservo.write(0);
     pushstate = 0; 
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
} 

void Task1() {
  int cdsvalue = analogRead(cds);
  Serial.print("CDS : ");
  Serial.println(cdsvalue);
  if (cdsvalue < 100)
  {
    bedroomservo.write(80);
  }
  else
  {
    bedroomservo.write(0);
  }
}

void Task2(){
  int flamevalue = analogRead(flame);
  Serial.print("flame : ");
  Serial.println(flamevalue);
  if (flamevalue < 400)
  {
    tone(buzzer, 956); 
  }
  else
  {
    noTone(buzzer);
  }
}

void Task3() {
  Liquid_level = digitalRead(notouch_water);
  Serial.print("Liquid_level = ");
  Serial.println(Liquid_level, DEC);
}
