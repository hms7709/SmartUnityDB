int Pin = A0;
int buzer = 5;
int distance = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(Pin, INPUT);
  pinMode(buzer, OUTPUT);
}

void loop() 
{
  int data = analogRead(Pin);
  int volt = map(data, 0, 1023, 0, 5000);
  distance = (27.61/(volt-0.1696))*1000;
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(" ");
  delay(500);

  if (distance < 20 && distance > 10)
  {
    digitalWrite(buzer, HIGH);
    delay(20);
  }

  else if (distance >= 20)
  {
    digitalWrite(buzer, LOW);
  }
}
