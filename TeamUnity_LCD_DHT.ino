#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal_I2C mylcd (0x27, 16, 2);
DHT mydht (4, DHT11);

int humiLED = 8;
float temp = 0;
float humi = 0;

void setup() {
  mylcd.init();
  Serial.begin(9600);
  mydht.begin();
  mylcd.backlight();
  pinMode(humiLED, OUTPUT);
}

void loop() {
  float temp = mydht.readTemperature();
  float humi = mydht.readHumidity();

  if(humi>70)
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
  Serial.print("humi: ");
  Serial.print(humi);
  Serial.print("%");
  mylcd.setCursor(0,0);
  mylcd.print("Temp = ");
  mylcd.print(Temp);
  mylcd.print(" C");
  mylcd.setCursor(0, 1); 
  mylcd.print("Humi = ");
  mylcd.print(humi);
  mylcd.print(" %");
  delay(500);
}
