#include <MsTimer2.h>
#include <SoftwareSerial.h>
int Tx = 10;
int Rx = 11;
SoftwareSerial BTSerial(Tx, Rx);
byte buffer[1024];
int bufferPosition;
unsigned long intervals[] = {1000, 1500};
unsigned long last[] = {0, 0};

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
  MsTimer2::set(1000, Task1);
}

void loop() {
  unsigned long now = millis();
  if (BTSerial.available()) {
    byte data = BTSerial.read();
    Serial.write(BTSerial.read());
    buffer[bufferPosition++] = data;

    if (data == 'a') // 주방 무드등 ON PWM
    {
        Task1();
    }

    else if (data == 'A') // 주방 무드등 OFF
    {
       analogWrite(9, 255);
       analogWrite(8, 255);    
       analogWrite(7, 255);
    } 
      
    else if (data == 'b') // 화장실 무드등
    {
      analogWrite(9, 0);
      analogWrite(8, 0);    
      analogWrite(7, 0);
    }
    
    else if (data == 'B')
    {
      analogWrite(9, 255);
      analogWrite(8, 255);    
      analogWrite(7, 255);
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

void Task1(){
     for (int i = 0; i <= 255; i++)
     {
        analogWrite(9, 0);
        analogWrite(8, i);
        analogWrite(7, 0); 
     }

     for (int i = 255; i >= 0; i--)
     {
        analogWrite(9, 0);
        analogWrite(8, i);
        analogWrite(7, i); 
     }
}
