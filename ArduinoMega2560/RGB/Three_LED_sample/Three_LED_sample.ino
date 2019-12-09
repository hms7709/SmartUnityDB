void setup() {
  // put your setup code here, to run once:

}

void loop() {
  analogWrite(9, 0);
  analogWrite(10, 255);
  analogWrite(11, 255);  // 빨간색

  analogWrite(9, 255);
  analogWrite(10, 0);    // 녹색
  analogWrite(11, 255);
 

  analogWrite(9, 255);
  analogWrite(10, 255);  // 파란색
  analogWrite(11, 0);
  

  analogWrite(9, 0);
  analogWrite(10, 0);    // 노란색
  analogWrite(11, 255);


  analogWrite(9, 0);
  analogWrite(10, 255);  // 보라색
  analogWrite(11, 0);


  analogWrite(9, 0);
  analogWrite(10, 0);    // 흰색
  analogWrite(11, 0);


  analogWrite(9, 255);
  analogWrite(10, 0);    // 청록색
  analogWrite(11, 0);

}
