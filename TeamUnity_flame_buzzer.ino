int led = 13;   //LED 13번 핀에 연결
int buzzer = 6;   //부저 6번 핀에 연결
int flame = 2;    //불꽃감지센서 2번 핀에 연결
int state = 0;    //불꽃감지센서 상태값 저장 변수

void setup() {
  pinMode(led, OUTPUT);   //led출력으로 설정
  pinMode(buzzer, OUTPUT);   //부저 출력으로 설정
  pinMode(flame, INPUT);    //불꽃감지센서 입력으로 설정
  Serial.begin(9600);      //9600 시리얼 통신에 표시
}

void loop() {
  state = digitalRead(flame);    //불꽃감지센서 상태값 입력받음
  digitalWrite(led, LOW);       //led 처음에는 꺼진 상태
  noTone(buzzer);         //부저 처음에는 꺼진 상태

  if (state == 0)         //불꽃감지센서 상태값 "0"일때(불꽃 감지된 상황)
  {
    Serial.println("ON");      //시리얼 통신창에 "ON"표시
    digitalWrite(led, HIGH);   //led 켬
    tone(buzzer, 500, 100);    //부저 500데시벨로 100동안 울림
    delay(100);
  }
  else                     //불꽃감지센서 상태값 "1"일때(불꽃 감지되지 않은 상황)
  {
    Serial.println("OFF");    //시리얼 통신창에 "Off"표시
    digitalWrite(led, LOW);    //led 끔
    noTone(buzzer);             //부저 끔
  }
  delay(100); 
}
