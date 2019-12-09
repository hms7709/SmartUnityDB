#include <SimpleTimer.h>
SimpleTimer timer;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
 timer.setTimeout(5000,fn);
 timer.run();
}

void fn(){
  digitalWrite(13, LOW);
}
