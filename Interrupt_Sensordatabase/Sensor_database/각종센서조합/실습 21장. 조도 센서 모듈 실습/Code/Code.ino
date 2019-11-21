//LK임베디드
int CDS_Sensor = A0; //A0에 센서연결
int Sensor_val;      //센서 ADC값 저장 변수
void setup(){ //초기화
  Serial.begin(9600);//시리얼통신 속도설정
}
/*조도센서의 값을 시리얼모니터를 통해 보여준다.*/
void loop(){ // 무한루프
  Sensor_val=analogRead(CDS_Sensor);//센서값을 읽어와서 Sensor_val에 넣는다  
  Serial.print("CDS value: ");  //시리얼 모니터에 CDS value: 출력
  Serial.println(Sensor_val);   //시리얼 모니터에 센서값 출력
  delay(500);  //0.5초 지연
}

