
int IN1 = 8;
int IN2 = 9;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  StartA();
  delay(3000);
  StopA();
  delay(3000);
}

void StartA()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  Serial.println("START");
}

void StopA()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("STOP");
}
