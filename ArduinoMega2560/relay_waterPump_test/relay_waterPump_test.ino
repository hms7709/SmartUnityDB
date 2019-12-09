int relay = 3;

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  digitalWrite(relay, HIGH);
  delay(3000);
  digitalWrite(relay, LOW);
  delay(3000000);
}
