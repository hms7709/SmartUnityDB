#include <Adafruit_NeoPixel.h>
#define NEO_PIN   2      // 네오픽셀 DI핀과 연결된 핀번호 설정
#define NUM_LEDS  12     // 네오픽셀 LED 갯수 설정

// 네오픽셀 라이브러리 funnyNeo 이름으로 연결
Adafruit_NeoPixel funnyNeo = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_GRBW + NEO_KHZ800);

int ledBright = 255;     // 초기 밝기 255(최대) 설정

// 아두이노 초기화
void setup() 
{
    funnyNeo.setBrightness(ledBright);  // 밝기 설정 ( 0 ~ 255 )
    funnyNeo.begin();                   // 네오픽셀 시작
    funnyNeo.show();                    // 네오픽셀 초기화
}

void loop() 
{
    int i;
    uint32_t colorValue;    // 색상값 저장 변수

    //빨간색 1바퀴 회전
    colorValue = funnyNeo.Color(255, 0, 0, 0);      // Red
    for(i = 0; i < NUM_LEDS; i++)
    {
        funnyNeo.setPixelColor(i, colorValue);
        funnyNeo.show();
        delay(50);
    }
    // 녹색 1바퀴 회전
    colorValue = funnyNeo.Color(0, 255, 0, 0);      // Green
    for(i = 0; i < NUM_LEDS; i++)
    {
        funnyNeo.setPixelColor(i, colorValue);
        funnyNeo.show();
        delay(50);
    }
    // 파랑색 1바퀴 회전
    colorValue = funnyNeo.Color(0, 0, 255, 0);      // Blue
    for(i = 0; i < NUM_LEDS; i++)
    {
        funnyNeo.setPixelColor(i, colorValue);
        funnyNeo.show();
        delay(50);
    }
    // 하얀색 1바퀴 회전
    colorValue = funnyNeo.Color(0, 0, 0, 255);      // White
    for(i = 0; i < NUM_LEDS; i++)
    {
        funnyNeo.setPixelColor(i, colorValue);
        funnyNeo.show();
        delay(50);
    }
}
