#include <SoftwareSerial.h>

int Tx = 10;
int Rx = 11;
SoftwareSerial BTSerial(Tx, Rx); 
byte buffer[1024];
int bufferPosition;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
}

void loop() {
    if (BTSerial.available()) {
      byte data = BTSerial.read();     // 수신 받은 데이터 저장
      Serial.write(BTSerial.read());   // 블루투스측 내용을 시리얼 모니터에 출력
      buffer[bufferPosition++] = data; // 수신 받은 데이터를 버퍼에 저장

      if (data == '0')
      {
        analogWrite(9, 0);
      } 

      else if (data == '1')
      {
        digitalWrite(9, 255);
      }

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
