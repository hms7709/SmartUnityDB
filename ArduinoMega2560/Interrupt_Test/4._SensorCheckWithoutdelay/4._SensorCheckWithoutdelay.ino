int lightPin = A0;
int humiPin = A1;
int ledPin = 13;
int buzzerPin = 8;

unsigned long checkMillis = 0;
unsigned long blinkMillis = 0;
unsigned long sendMiliiis = 0;
int blinkCnt = 0;

boolean ledState = LOW;

int lightValue = 0;
float humValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
}

void loop() {
  unsigned long curMillis = millis();
  if(curMillis - checkMillis > 100)
  {
    checkMillis = curMillis;
    lightValue = analogRead(lightPin);
    humValue = analogRead(humiPin);

    if((lightValue > 500) && (blinkCnt == 0))
    {
      blinkMillis = curMillis;
      blinkCnt = 6;
    }
  }

  if(curMillis - sendMillis > 1000)
  {
    sendMillis = curMillis;
    Serial.println(humiValue);
  }

  if(blinkCnt > 0)&&(curMillis - blinkMillis > 1000)) {
    blinkMillis = curMillis;
    blinkCnt--;
    if(ledState == LOW)
    {
      ledState = HIGH;
      digitalWrite(ledPin, HIGH);
    }
    else
    {
      ledState = LOW;
      digitalWrite(ledPin, LOW);
    }
  }
}

void serialEvent() {
  char c = Serial.read();
  if (c == 'A') {
    tone(buzzerPin, 1000, 100);
  }
}
