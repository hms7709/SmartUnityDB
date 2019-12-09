#include <Servo.h>

int servoPin = 5;
int pushbutton = 2;

Servo myservo;

void setup() {
  myservo.attach(servoPin);
  pinMode(pushbutton, INPUT_PULLUP);
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
}
