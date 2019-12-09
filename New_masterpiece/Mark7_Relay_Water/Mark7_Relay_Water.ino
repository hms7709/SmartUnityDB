int relay = 3; // 5V 어댑터로 구동

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  digitalWrite(relay, HIGH);
  delay(3000);
  digitalWrite(relay, LOW);
  delay(3000000);

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
