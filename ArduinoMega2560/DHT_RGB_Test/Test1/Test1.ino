#include <SimpleTimer.h>
#include <SoftwareSerial.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);
DHT DHTsensor (4, DHT11);
SimpleTimer timer;
int humiLED = 8;
const long interval = 1000;
int RGB [] = {9, 10, 11};
unsigned long previousMillis = 0;
unsigned long RedPretime = 0;

void setup() {
  mylcd.init();
  Serial.begin(9600);
  DHTsensor.begin();
  mylcd.backlight();
}

void loop() {
  unsigned long currentMillis = millis();
  unsigned long Curtime = millis();
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    float humi = DHTsensor.readHumidity();
    float temp = DHTsensor.readTemperature();

    Serial.print("Temp : ");
    Serial.print(temp);
    Serial.print("C ");
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
    
    if (humi > 60)
    {
      digitalWrite(humiLED, HIGH);
    }
    else
    {
      digitalWrite(humiLED, LOW);
    }

    if(Curtime - RedPretime >= interval - 500)
    {
      RedPretime = Curtime;
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 255);  // 빨간색
    }
  }
}
