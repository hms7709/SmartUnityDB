#include <SoftwareSerial.h>
int led1 = 30;
int led2 = 32;
int led3 = 34;
int Tx = 10;
int Rx = 11;

SoftwareSerial BTSerial(Tx, Rx);

void setup() 
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() 
{
  if(BTSerial.available())
  {
    char buf;
    buf = BTSerial.read();
    if (buf == 'a')
    {
      digitalWrite(led1, HIGH);
    }
    if (buf == 'b')
    {
      digitalWrite(led2, HIGH);
    }
    if (buf == 'c')
    {
      digitalWrite(led3, HIGH);
    }
    if (buf == 'd')
    {
      digitalWrite(led1, LOW);
    }
    if (buf == 'e')
    {
      digitalWrite(led2, LOW);
    }
    if (buf == 'f')
    {
      digitalWrite(led3, LOW);
    }
  }
  if(Serial.available())
  {
    BTSerial.write(Serial.read());
  }
}
