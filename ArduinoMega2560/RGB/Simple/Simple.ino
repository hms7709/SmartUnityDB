unsigned long intervals[] = {250, 1000, 1500, 2000, 2500, 3000, 3500, 4000};
unsigned long last[] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
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

  if(now - last[2] >= intervals[2])
  {
     last[2] = now;
     thirdTask();
  }

  if(now - last[3] >= intervals[3])
  {
     last[3] = now;
     fourTask();
  }

  if(now - last[4] >= intervals[4])
  {
     last[4] = now;
     fiveTask();
  }

  if(now - last[5] >= intervals[5])
  {
     last[5] = now;
     sixTask();
  }

  if(now - last[6] >= intervals[6])
  {
     last[6] = now;
     sevenTask();
  }

  if(now - last[7] >= intervals[7])
  {
     last[7] = now;
     eightTask();
  }
}

void firstTask(){
  //let's toggle the built-in led
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)?0:1);
}

void secondTask(){
     analogWrite(9, 0);
     analogWrite(10, 255);
     analogWrite(11, 255);  
}

void thirdTask(){
     analogWrite(9, 255);
     analogWrite(10, 0);
     analogWrite(11, 255); 
}

void fourTask(){
     analogWrite(9, 255);
     analogWrite(10, 255);
     analogWrite(11, 0); 
}

void fiveTask(){
     analogWrite(9, 0);
     analogWrite(10, 0);
     analogWrite(11, 255); 
}

void sixTask(){
     analogWrite(9, 0);
     analogWrite(10, 255);
     analogWrite(11, 0); 
}

void sevenTask(){
     analogWrite(9, 255);
     analogWrite(10, 0);
     analogWrite(11, 0); 
}

void eightTask(){
     analogWrite(9, 0);
     analogWrite(10, 0);
     analogWrite(11, 0); 
}
