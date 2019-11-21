//LK임베디드
int Sound_Sensor = A0; //A0에 센서연결
int Sensor_val;        //센서 ADC값 저장 변수
int count_clap;        //박수소리 횟수 카운트
void setup(){ // 초기화
  Serial.begin(9600);//시리얼통신 속도설정 
}
/*소리의 발생횟수를 카운트해서 시리얼 모니터에 표시한다.*/
void loop(){ // 무한루프
  Sensor_val=analogRead(Sound_Sensor);//센서값을 읽어와서 Sensor_val에 넣는다  
  
  if(Sensor_val<=28){  //만약 센서값이 28보다 작거나 같으면
    count_clap++;      //count_clap의 값을 1증가시킨다
    Serial.println(count_clap); //시리얼 모니터로 count_clap의 값을 출력후 한줄 내린다
    delay(20); //노이즈에 의한 역속적인 감지를 방지하기 위해 20ms 지연
  }
}

