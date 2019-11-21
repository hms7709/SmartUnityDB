
const int A1A = 8;
const int A1B = 9;

void setup() {
  pinMode(A1A, OUTPUT);
  pinMode(A1B, OUTPUT);
}

void loop() {
  digitalWrite(A1A, HIGH);
  digitalWrite(A1B, LOW);
}
