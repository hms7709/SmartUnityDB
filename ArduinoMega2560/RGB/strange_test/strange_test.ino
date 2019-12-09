void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  if(analogRead(9))
  {
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
}
