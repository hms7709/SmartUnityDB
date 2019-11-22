#include "DM_G_I2C.h" 
#include <SPI.h> 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>


// ##2. Setup()문
void setup() {
 // 1) 시리얼 통신 설정 - 컴퓨터를 통해 진행 상태 확이 할 수 있음 : 시리얼 모니터 하기 위한 설정
  Serial.begin(9600);         
 // 2) I2C스캐널르 통해 현재 회로가 잘 연결 됬는지 확인 할 수 있음
  G_I2C_Scanner(); 
  delay(1000); 
 // 3) OLED 초기설정 하기  
  OLED_SETUP();

}

// ##3. Image-프로그램 값
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  

// ##4. Loop문
void loop() {
// Pixel Size : 128_32 Display Size - Pixel
// Color : BLACK 0, WHITE 1, INVERSE 2

//1) 이미지 출력
 OLED_Display_Image(2000, logo16_glcd_bmp);

//2) 닦아 내기 
 OLED_Display_clear_white_h();
//3) 닦아 내기 (2)
 OLED_Display_clear_white_w();

//3) 글씨 출력 - 폰트1
 OLED_Display(1,0,0,"No.1 BLOG!");
 delay(1000);
 OLED_Display_add(1,0,15,"DEVICEMART");
 delay(1000);
//4) 인벌스 시키기
 OLED_Display_Full_Inverse_w();
 delay(1000);
//5) 글씨 출력 - 폰트2
 OLED_Display(2,0,0,"No.1 BLOG!");
 delay(1000);
 OLED_Display_add(2,0,15,"DEVICEMART");
 delay(1000);
//4) 인벌스 시키기
 OLED_Display_Full_Inverse_h();
 delay(1000);
//6) 위 or 아래 쉬푸트 
 OLED_Display_clear_display();
 OLED_Display_Font2_RIGHT_up(200, "DEVICEMART");
 OLED_Display_Font2_RIGHT_do(200, "No.1 BLOG!");
//6) 위 & 아래 쉬푸트 
 OLED_Display_clear_display();
 OLED_Display_Font2_RIGHT_with(200, "DEVICEMART", "No.1 BLOG!");


 
}

/*
void G_I2C_Scanner();
void initial_serial_print();
void OLED_SETUP();
void OLED_Display(int Fontsize,int oled_x_set,int oled_y_set, String message);
void OLED_Display_add(int Fontsize,int oled_x_set,int oled_y_set, String message);

void OLED_Display_Font2_RIGHT_up(int delaytime, String message);
void OLED_Display_Font2_RIGHT_do(int delaytime, String message);
void OLED_Display_Font2_RIGHT_with(int delaytime, String message1, String message2);


void OLED_Display_clear();
void OLED_Display_clear_display();
void OLED_Display_display();

void OLED_Display_clear_white_h();
void OLED_Display_clear_white_w();
void OLED_Display_Full_Inverse_w();
void OLED_Display_Full_Inverse_h();


void OLED_Display_dot(int x, int y, int State);

void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h);

void OLED_Display_Image(int delay_time,unsigned char PROGMEM Data[]);
*/
