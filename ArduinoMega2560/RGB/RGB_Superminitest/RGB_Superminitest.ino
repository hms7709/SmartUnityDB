int RGB [] = {9, 10, 11};

void setup() {
  pinMode (RGB[0], OUTPUT);      // Red
  pinMode (RGB[1], OUTPUT);      // Green
  pinMode (RGB[2], OUTPUT);      // Blue
}

void loop() {
  analogWrite(RGB[0], 255);
  analogWrite(RGB[0], 0);
  delay(1000);
}
