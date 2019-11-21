#include <Stepper.h>
 
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution,8, 9); 
 
void setup() {
  myStepper.setSpeed(60); 
  Serial.begin(9600);     
}

void loop() {
  Serial.println("counterclockwise");
  myStepper.step(stepsPerRevolution);
  delay(1000);
 
  Serial.println("clockwise");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
