int relay = 3; // 5V 어댑터로 구동

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {

  analogWrite(10, 0);
  analogWrite(9, 0);
  analogWrite(8, 255);
  digitalWrite(relay, HIGH);
  delay(8U000);
  analogWrite(10, 255);
  analogWrite(9, 0);
  analogWrite(8, 0);
  digitalWrite(relay, LOW);
  delay(3000000);
}
