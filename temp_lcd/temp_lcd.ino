#include <LiquidCrystal_I2C.h>
#include<DHT.h>     //DHT.h 라이브러리 추가

LiquidCrystal_I2C lcd(0x3f, 16,2);
DHT dht(12, DHT11); //DHT 설정 dht(핀, DHT종류)

void setup() 
{
  Serial.begin(9600); //시리얼모니터 시작
  lcd.init();
  lcd.backlight();
}

void loop() {
  int tem = dht.readTemperature();  //온도 값 정수형 변수 tem
  int hum = dht.readHumidity();     //습도 값 정수형 변수 hum
  Serial.print("Tem :   ");    
  Serial.print(tem);               
  Serial.print("C ");               
  Serial.print("Hum:    ");
  Serial.print(hum);
  Serial.println("% ");             
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(tem, 7);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi : ");
  lcd.print(hum, 7);
  lcd.print(" %");
  delay(2000);
  lcd.clear();
  
}
