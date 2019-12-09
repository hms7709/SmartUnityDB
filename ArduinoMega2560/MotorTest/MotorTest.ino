#include <Servo.h>

int servoPin = 10;

Servo myservo;

void setup() {
  myservo.attach(servoPin);
}

void loop() {
    myservo.write(179);
    delay(1000);
    myservo.write(0);
    delay(1000);
}
