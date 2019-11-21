//LK임베디드
#include <Wire.h>  // Wire 헤더파일 호출

char HUMI_Sensor = A0; // A0에 센서연결
int Sensor_val;        // 센서 ADC값 저장 변수

byte dht11_dat[5];   // 센서변수
byte dht11_in;       // 센서변수
byte i;
byte read_dht11_dat()  // 온도습도 센서 모듈 값 읽어오는 함수
{
  byte i = 0;          // for문 변수
  byte result=0;       // 리턴변수
  for(i=0; i< 8; i++)  // for문 9번 반복
  {
    while (!digitalRead(HUMI_Sensor));  // 센서 값이 1이 될 때까지 무한루프
    delayMicroseconds(30);              // 30마이크로세크 대기
    if (digitalRead(HUMI_Sensor) != 0 ) // 만약 센서 값이 0과 같지 않으면
      bitSet(result, 7-i);              // bitSet(n,x) n이라는 변수에 x번째의 비트 ON
    while (digitalRead(HUMI_Sensor));  // 센서 값이 0이 될 때까지 무한루프
  }
  return result;                       // result의 값을 리턴 
}
void setup()  // 초기화
{
  Serial.begin(9600);                    //시리얼 통신속도 설정 
  pinMode(HUMI_Sensor, OUTPUT);           //센서 출력 설정 
  digitalWrite(HUMI_Sensor, HIGH);        //센서값 HIGH
}
/*센서를 이용해서 온도와 습도를 측정해서 모니터에 표시 */
void loop()  // 무한루프
{
  digitalWrite(HUMI_Sensor, LOW);  //센서핀을 off한다
  delay(18);                       //18ms만큼 지연
  digitalWrite(HUMI_Sensor, HIGH); //센서핀을 on한다
  delayMicroseconds(5);            //5us만큼 지연
  pinMode(HUMI_Sensor, INPUT);     //센서핀을 입력으로 설정한다
  delayMicroseconds(200);          //200us만큼 지연
  for (i=0; i<5; i++) {dht11_dat[i] = read_dht11_dat();}  
  //40bit의 데이터를 수신합니다. 자세한 사항은 DHT11의 데이터시트를 참고
  pinMode(HUMI_Sensor, OUTPUT);    //센서 핀을 출력 설정
  digitalWrite(HUMI_Sensor, HIGH); //센서 값 HIGH
  byte dht11_check_sum = dht11_dat[0]+dht11_dat[2];  // check check_sum
  
  Serial.print(dht11_dat[0], DEC);   // 모니터에 습도값 출력
  Serial.print('%');                 // 모니터에 % 출력
  Serial.print(dht11_dat[2], DEC);   // 모니터에 온도값 출력
  Serial.println('C');               //모니터에 C 출력
  delay(2000); //2초간 지연
}


