#include <SoftwareSerial.h>

#include <Servo.h>

unsigned long curtime = 0;
unsigned long previoustime = 0;

int arr[] = {2, 3, 9, 13}
SoftwareSerial BTSerial(arr[0], arr[1]);
Servo myservo;


void setup() {
  Serial.begin(9600);
  myservo.attach(pin);
}

void loop() {

  if(BTSerial.available())
  {
    Serial.read();
    byte data;
    if ()
    {
      digitalWrite(arr[3], HIGH);
      myservo.write(arr[2]);
    }
    else if (data = '0')
    {
      digitalWrite(arr[3], LOW);
    }
  }
  if(Serial.available())
  {
    
  }

}
