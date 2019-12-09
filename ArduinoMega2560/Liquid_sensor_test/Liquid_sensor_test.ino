int Liquid_level = 0;

void setup() {
  Serial.begin(9600);
  pinMode (12, INPUT);
}

void loop() {
  Liquid_level = digitalRead(12);
  Serial.print("Liquid_level = ");
  Serial.println(Liquid_level, DEC);
  delay(500);
}
