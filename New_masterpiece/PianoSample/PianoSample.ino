# include "pitches.h"
               
void setup() {
  Serial.begin(9600);
  pinMode (8, INPUT_PULLUP);
  pinMode (9, INPUT_PULLUP);
  pinMode (10, INPUT_PULLUP);
  pinMode (2, OUTPUT);
}

void loop() {
  if(digitalRead(8) == LOW)
  {
    tone (2, 262);
    servo.write(30);
  }
  else if(digitalRead(9) == LOW)
  {
    tone (2, 294);
    servo.write(60);
  }
  else if(digitalRead(10) == LOW)
  {
    tone (2, 330);
    servo.write(90);
  }
  else 
  {
    noTone (2);
  } 
}
