#include <Servo.h>

Servo myservo;
Servo myservo2;
int servoPin = 6;
int servoPin2 = 8;

void setup() {
  myservo.attach(6);
  myservo2.attach(8);
  myservo.write(90);
  myservo2.write(90);
  myservo.attach(servoPin);
  myservo2.attach(servoPin2);
}

void loop() {
  int angle;

  for (angle = 60; angle < 180; angle++)
  {
    myservo.write(angle);
    myservo2.write(angle);
    delay(20);
  }

  for (angle = 180; angle > 60; angle--)
  {
    myservo.write(angle);
    myservo2.write(angle);
    delay(20);
  }
}
