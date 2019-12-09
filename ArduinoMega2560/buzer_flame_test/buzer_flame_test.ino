int buzzer = 8;
unsigned long intervals[] = {1000, 1500};
unsigned long last[] = {0, 0};
int flame = A1;

void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);    
}
void loop()
{
  unsigned long now = millis();
  if(now - last[0] >= intervals[0])
  {
     last[0] = now;
     firstTask();
  }
  if(now - last[1] >= intervals[1])
  {
     last[1] = now;
     secondTask();
  }
}

void firstTask(){
  //let's toggle the built-in led
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)?0:1);
}

void secondTask(){
  int flamevalue = analogRead(flame);
  Serial.println(flamevalue);
  if (flamevalue < 100)
  {
    tone(buzzer, 956); 
  }
  else
  {
    noTone(buzzer);
  }
}                        
