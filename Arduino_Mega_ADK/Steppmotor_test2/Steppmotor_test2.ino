#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, 5, 6);

void setup() {
  myStepper.setSpeed(98);
  Serial.begin(9600);
}

void loop() {
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  //delay(1500);

  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution);
  //delay(1500);
  
}
