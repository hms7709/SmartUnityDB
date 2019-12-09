#include <SimpleTimer.h>
SimpleTimer timer;
boolean leds = false;

void setup() {
  pinMode(13, OUTPUT);
  timer.setInterval(1000, fn);
}

void loop() {
  timer.run();
}

void fn() {
  if (leds == true)
  {
    digitalWrite(13, LOW);
  }
  else
  {
    digitalWrite(13, HIGH);
  }
  leds =! leds;
}
