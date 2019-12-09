#include <DHT.h>
#include <DHT_U.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd (0x27, 16, 2);
DHT DHTsensor (4, DHT11);
int humiLED = 8;

const long interval = 3000;
unsigned long previousMillis = 0;

void setup() {
  mylcd.init();
  Serial.begin(9600);
  DHTsensor.begin();
  mylcd.backlight();
  pinMode(humiLED, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
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
    
    if (humi > 70)
    {
      digitalWrite(humiLED, HIGH);
    }
    else
    {
      digitalWrite(humiLED, LOW);
    }
  }   
}
