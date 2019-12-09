
void setup() {
   pinMode(30, OUTPUT);
   pinMode(31, OUTPUT);
}

void loop() {
  digitalWrite(30, HIGH);
  digitalWrite(31, HIGH);
  delay(1000);
  digitalWrite(30, LOW);
  digitalWrite(31, LOW);
  delay(1000);
}
