//조도센서를 활용한 도난방지장치
void setup() 
{
 pinMode(6,OUTPUT); // 초록LED
 pinMode(7,OUTPUT); // 빨강LED
 pinMode(5,OUTPUT); // 부저
 Serial.begin(9600);
 
}

void loop() 
{  
  int lit = 0; // 조도센서 변수설정
  lit = analogRead(A0); 
  Serial.println(lit); // 조도센서 모니터링
  delay(100);

  if(lit > 240)  //안전한 상태 (평소 260) 어두워지면 조도센서증가
  {
    digitalWrite(5,LOW);  //  부저 OFF
    digitalWrite(6,HIGH); //  초록불 ON
    digitalWrite(7,LOW);  //  빨강 OFF
  }
  else if (lit >100)    // 100을 넘게 되면 버저 울림 
  {
    digitalWrite(5,HIGH);  //부저 ON
    digitalWrite(6,LOW);   //초록불 OFF
    digitalWrite(7,HIGH);  //빨강불 ON
  }
}
