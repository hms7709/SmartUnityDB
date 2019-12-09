int fenceLED = 22;
int yardLED = 23;

void setup() {
  pinMode(fenceLED, OUTPUT);
  pinMode(yardLED, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
}

void loop() {
   digitalWrite(fenceLED, HIGH);
   digitalWrite(yardLED, HIGH);
   analogWrite(30, 0);
   analogWrite(31, 255);
   analogWrite(32, 0);
   digitalWrite(24, 255);
   digitalWrite(25, 0);
   digitalWrite(26, 255);
   digitalWrite(27, 0);
   digitalWrite(28, 0);
   digitalWrite(29, 255);
   delay(1000);
   digitalWrite(fenceLED, LOW);
   digitalWrite(yardLED, LOW);
   analogWrite(30, 0);
   analogWrite(31, 0);
   analogWrite(32, 255);
   digitalWrite(24, 255);
   digitalWrite(25, 255);
   digitalWrite(26, 0);
   digitalWrite(27, 255);
   digitalWrite(28, 0);
   digitalWrite(29, 255);
   delay(1000);
}
