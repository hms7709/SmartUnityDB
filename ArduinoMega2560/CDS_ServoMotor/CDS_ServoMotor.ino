#include <Servo.h>
Servo myservo;
unsigned long intervals[] = {1000, 1500};
unsigned long last[] = {0, 0};
int cds = A0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  if(now - last[0] >= intervals[0])
  {
     last[0]=now;
     firstTask();
  }
  if(now - last[1] >= intervals[1])
  {
     last[1]=now;
     secondTask();
  }
}

void firstTask(){
  //let's toggle the built-in led
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)?0:1);
}

void secondTask(){
  boolean ledState = LOW;
  int cdsvalue = analogRead(cds);
  Serial.println(cdsvalue);
  if (cdsvalue < 100)
  {
    myservo.write(179);
  }
  else
  {
    myservo.write(0);
  }
}
