int pushButton = 2;
int led = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(pushButton);

  if(buttonState == 1)
  {
    digitalWrite(led, LOW);
    Serial.println(buttonState);
    delay(1);
  }

  if(buttonState == 0)
  {
    digitalWrite(led, HIGH);
    Serial.println(buttonState);
    delay(1);
  }
}
