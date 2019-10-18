#include <Servo.h>

Servo myservo;
int motor = 0; //서보모터 변수
int lit = 0;   //조도센서 변수
void setup() 
{
  myservo.attach(9);
  Serial.begin(9600);
 
}

void loop() 
{  
  lit = analogRead(A0); 
  Serial.println(lit); // 조도센서 모니터링
  delay(100);

  if(lit >= 100 && lit < 200)  //  빛을 받고있는상태
  {  
    for(motor = 0; motor < 180; motor += 1)  // 0도에서 180도로 이동합니다.                               // 이동할때 각도는 1도씩 이동합니다. 
    myservo.write(motor);              // 'pos'변수의 위치로 서보를 이동시킵니다.
    delay(25);                       //  
  } 
  else if (lit >= 500 && lit <=800)   어두워지면 
  {                                    
    for(motor = 180; motor >= 10; motor -=1)  // 180도에서 10도로 이동합니다.                                   
    myservo.write(motor);              // 서보를 반대방향으로 이동합니다.
    delay(25);                       //   
  } 
}
