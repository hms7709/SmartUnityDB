int buzer = 6;
void setup() {
  Serial.begin(9600);
  pinMode(buzer, OUTPUT);
}

void loop() {
  unsigned long curMillis1 = millis();
  unsigned long curMillis2 = millis();
  int flame = analogRead(A2);
  if (flame < 60)
  {
    digitalWrite(buzer, HIGH);
  }
  Serial.print("불꽃센서값 :  ");
  Serial.println(flame);
}
