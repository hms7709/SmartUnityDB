int sw = 8;
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(sw) == LOW)
  {
    digitalWrite(led, HIGH);
  }
  else 
  {
    digitalWrite(led, LOW);
  }
}
