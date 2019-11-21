int SW_Pin = 7;    //스위치 핀번호
int Laser_Pin = 2; //레이저 핀번호

int cot = 0;//스위치 입력 유지 변수
 
void setup()  // 초기화
{
 pinMode(SW_Pin, INPUT_PULLUP);//스위치를 풀업입력으로 설정한다.
 pinMode(Laser_Pin, OUTPUT);//레이저를 출력으로 설정한다.
}
/*버튼을 한번 누르면 레이저가 ON되고 다시한번 누르면 OFF된다.*/ 
void loop()  // 무한루프
{
  if(digitalRead(SW_Pin)==LOW){    //만약 스위치가 눌리면
    cot^=true;  //cot의 값을 반전시킨다.
    delay(300);//챕터링 방지용 0.3초
  }
  if(cot == true){//만약 cot의 값이 참이면
    digitalWrite(Laser_Pin,HIGH);//레이저를 ON해라
  }
  else{//cot의 값이 참이 아니면
   digitalWrite(Laser_Pin,LOW);//레이저를 OFF해라
  }  
}
