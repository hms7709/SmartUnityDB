#include <DHT.h> //온습도 센서 라이브러리 사용
#define DHTPIN 2 // 습도센서 Signal 선 연결
#define DHTTYPE DHT11
#include <SoftwareSerial.h> // 시리얼 통신
//#include <dht11.h> // dht11.h 라이브러리를 불러옵니다.
int Tx = 6; // 전송 핀
int Rx = 7;// 수신 핀
//DHT11 dht11(sensorPin);
float hum;
float temp;
SoftwareSerial btSerial(6,7);
DHT dht(DHTPIN, DHTTYPE);
void setup()
{
  Serial.begin(9600);  //모니터링핀
  btSerial.begin(9600); // 보드레이트 9600으로 통신
  dht.begin();  //온습도 핀
}
void loop()
{
    hum = dht.readHumidity();//온도값 읽기
    temp= dht.readTemperature();//습도값 읽기
    char data[7] = {0,};
    sprintf(data,"%03d%03d",hum,temp); //습도, 온도를 049020 형태로 표시합니다.(49%, 20C일때)
    Serial.println(hum);
    Serial.println(temp);
    delay(1000);
    btSerial.println(hum);
    btSerial.println(temp);
    delay(1);
// while(Serial.available())
// {
// btSerial.print(data);
// delay(1);
// }
}
