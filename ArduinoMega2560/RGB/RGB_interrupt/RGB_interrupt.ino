#include <MsTimer2.h>

int RGB [] = {9, 10, 11};
unsigned long previousMillis = 0;
const long interval = 1000;
int ledState = 0;

void setup() {
  pinMode (RGB[0], OUTPUT);      // Red
  pinMode (RGB[1], OUTPUT);      // Green
  pinMode (RGB[2], OUTPUT);      // Blue
}

void red()
{
  unsigned long currentMillis = millis();
  
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], i);  // 빨간색
    if ((currentMillis - previousMillis >= interval) && (i == 0))
    {
      analogWrite(RGB[0], 0);
      for (int i = 1; i < 255; i++)
      {
        analogWrite(RGB[0], i);
        analogWrite(RGB[1], 0);
        analogWrite(RGB[2], 0);  // 빨간색
      }
    }
  }
}

void green()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], i);  // 녹색
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], 0);  // 녹색
    delay(10);
  } 
}

void blue()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], 0);  // 파란색
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], i);  // 파란색
    delay(10);
  } 
}

void yellow()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], i);  // 노란색
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], 0);  // 노란색
    delay(10);
  } 
}

void lightblue()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], 0);
    delay(10);  
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], 0);
    delay(10);  
  } 
}

void purple()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], 0);
    delay(10);  
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], 0);
    delay(10);  
  } 
}

void white()
{
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(RGB[0], 0);
    analogWrite(RGB[1], 0);
    analogWrite(RGB[2], 0);  // 흰색
    delay(10);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(RGB[0], i);
    analogWrite(RGB[1], i);
    analogWrite(RGB[2], i);  // 흰색
    delay(10);
  } 
}

void loop() {
  red();
}