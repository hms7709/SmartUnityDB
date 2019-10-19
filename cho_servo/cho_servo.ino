#include <Servo.h>

//초음파 + 서보 = 자동문 
Servo myservo;
int echoPin = 12; //초음파 센서의 핀번호
int trigPin = 13;
int motor = 0; //서보모터 변수

void setup() 
{
  Serial.begin(9600);
  // trig를 출력모드로 설정, echo를 입력모드로 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
}

void loop() 
{
  float duration, distance;

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  
  // echoPin 이 HIGH를 유지한 시간을 저장 한다.
  duration = pulseIn(echoPin, HIGH); 
  // HIGH 였을 때 시간(초음파가 보냈다가 다시 들어온 시간)을 가지고 거리를 계산 한다.
  distance = ((float)(340 * duration) / 10000) / 2;  

   if(distance <= 10 )  //  사람이 문앞까지오면 열림
  {  
    delay(2000);  // 사람이 들어가고 나가는 시간고려 딜레이1
    for(motor = 0; motor < 180; motor += 1)  // 0도에서 180도로 이동합니다.                               // 이동할때 각도는 1도씩 이동합니다. 
    myservo.write(motor);              // 'motor'변수의 위치로 서보를 이동시킵니다.
  } 
  else if (distance <= 500)  // 눈앞에 사람이 없으면 닫힘
  {                                    
    delay(2000); // 사람이 들어가고 나가는 시간고려 딜레이2
    for(motor = 180; motor >= 10; motor -=1)  // 180도에서 10도로 이동합니다.                                   
    myservo.write(motor);              // 서보를 반대방향으로 이동합니다.                    
  } 
  
  Serial.print(distance); //초음파 시리얼모니터링
  Serial.println("cm");
  delay(500);


  
}
