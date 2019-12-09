int bts[] = {4, 5, 6};
int notes[] = {523, 587, 659};

void setup() {
  for (int i = 0; i < 3; i++)
  {
    pinMode(bts[i], INPUT);
  }
  pinMode(11, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++)
  {
    if (digitalRead(bts[i] == HIGH)
    {
      tone(11, notes[i], 100);
      delay(100);
      noTone(11);
    }
  }
}
