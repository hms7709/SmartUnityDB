#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SoftwareSerial.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);
DHT DHTsensor (4, DHT11);
int humiLED = 8;
const long interval = 1000;
unsigned long previousMillis = 0;
int yardLED[]  = {22, 23, 24, 25, 26, 27, 28, 29}; 
int fenceLED[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43};
int Tx = 10; //전송
int Rx = 11; //수신
byte buffer[1024];
int bufferPosition;
SoftwareSerial BTSerial(Tx, Rx);

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
  pinMode(humiLED, OUTPUT);
  mylcd.init();
  mylcd.backlight();
  DHTsensor.begin();
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
}

void loop() {
  // 거실----------------------------
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
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
  } // 거실--------------------------
  
  if (BTSerial.available()) {
    byte data = BTSerial.read();     // 수신 받은 데이터 저장
    Serial.write(BTSerial.read());   // 블루투스측 내용을 시리얼 모니터에 출력
    buffer[bufferPosition++] = data; // 수신 받은 데이터를 버퍼에 저장

    if (data == 'a')
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

    if (data == 'b')
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
    if (data == 'A') 
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
    if (data == 'B')
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
  }
}
