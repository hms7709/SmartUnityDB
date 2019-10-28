#include <LiquidCrystal_I2C.h>

#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal_I2C mylcd (0x27, 16, 2);
//SoftwareSerial mybluetooth(2, 3);
DHT mydht (4, DHT11);

int humiLED = 8;
float temp = 0;
float humi = 0;

void setup() 
{
  mylcd.init();
  //mybluetooth.begin (9600);
  Serial.begin(9600);
  mydht.begin();  // 온도센서 초기화
  mylcd.backlight();
  pinMode(humiLED, OUTPUT);
}

void loop() 
{
  float temp = mydht.readTemperature();
  float humi = mydht.readHumidity();
  //mybluetooth.print ("온도 : ");
  //mybluetooth.print (temp);
  //mybluetooth.print ("   ");
  //mybluetooth.print ("습도 : ");
  //mybluetooth.println (humi);
  
  if (humi > 70)
  {
    digitalWrite(humiLED, HIGH);
  }
  else
  {
    digitalWrite(humiLED, LOW);
  }
  
  Serial.print("Temp : ");
  Serial.print(temp);
  Serial.print("C");
  Serial.print("humi : ");
  Serial.print(humi);
  Serial.println("%");
  mylcd.setCursor(0, 0);
  mylcd.print("Temp = ");
  mylcd.print(temp);
  mylcd.print(" C");
  mylcd.setCursor(0, 1);
  mylcd.print("Humi = ");
  mylcd.print(humi);
  mylcd.print( "%");
  delay(500);
}
