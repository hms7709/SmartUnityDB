#include <SoftwareSerial.h>
 
int Tx = 10; //전송
int Rx = 11; //수신
 
SoftwareSerial btSerial(Tx, Rx);
 
void setup() 
{
  Serial.begin(9600);
  btSerial.begin(9600);
}
 
void loop()
{
  if (btSerial.available()) {       
    Serial.write(btSerial.read());
  }
  if (Serial.available()) {         
    btSerial.write(Serial.read());
  }
}
