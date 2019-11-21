#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);       // I2C LCD 객체인 lcd를 설정합니다. (I2C주소,가로크기,세로크기)입니다.
#include <Wire.h>                             //Wire 라이브러리를 불러옵니다.


/*
I2C 통신은 각 제품마다 주소가 있어 그 주소를 알아야 통신을 할 수 있습니다.
I2C 주소는 I2C 스캐너를 통해 알 수 있으며, 첨부한 I2C_Scanner.ino 파일을 통해 알 수 있습니다.
*/
int val;                                        // val이라는 변수를 선언합니다.
void setup()
{
  lcd.init();                               // lcd를 설정합니다.
  lcd.backlight();                          // 백라이트를 켜줍니다.
  lcd.clear();                               // lcd 화면을 지웁니다.
  val = 0;                                     // val을 0으로 정합니다.
}
void loop()
{
  lcd.clear();                                        // lcd의 화면을 지웁니다.
  lcd.setCursor(0, 0);                            // lcd의 0,0을 지정합니다.
  lcd.print("hello, world!");                     // hello, world! 라는 문장을 출력합니다.
  lcd.setCursor(0, 1);                            // lcd의 0,1을 지정합니다.
  lcd.print(val);                                     // val의 값을 출력합니다.
  lcd.display();                                     // 설정된 내용들을 lcd에 출력합니다.
  delay(1000);                                       // 1초동안 기다립니다.
  val ++;                                               // val 값을 1만큼 높힙니다.
}
