int S = A0; //센서 입력핀을 A0핀으로 설정

void setup()  // 초기화
{
 Serial.begin(9600); // 시리얼 통신 초기화
}
/*자석의 N극과 S극을 구분해서 시리얼 모니터에 표시한다.*/
void loop()  // 무한루프
{
 if(analogRead(S)>=600){  //만약센서값이 600보다 크면
   Serial.println("S");  //시리얼 모니터로 'S' 출력
  }
  else if(analogRead(S)<=400){  //만약 센서값이 400보다 작으면
   Serial.println("N");  //시리얼 모니터로 'N' 출력
  }
  else{//센서의 값이 401보다 크거나 599보다 작으면 
   Serial.println("NO Magnet");//시리얼 모니터로 'No magnet' 출력
  }
 delay(500);  //0.5초 지연
}
