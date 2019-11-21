#define joystick_x A2  // 조이스틱 X 연결 핀
#define joystick_y A1  // 조이스틱 Y 연결 핀
#define joystick_sw A0  // 조이스틱 스위치 연결 핀
void setup()  // 초기화
{
  Serial.begin(9600);  // 시리얼 통신 속도를 설정
  pinMode(joystick_x, INPUT);  // 조이스틱의 X 핀 입력 설정
  pinMode(joystick_y, INPUT);  // 조이스틱의 Y 핀 입력 설정
  pinMode(joystick_sw, INPUT);  // 조이스틱의 스위치 핀 입력 설정
}
void loop()  // 무한루프
{
  Serial.print("  X : ");  // 시리얼 모니터에 “  X : “출력
  Serial.print(analogRead(joystick_x));  // x값을 읽어와 시리얼 모니터에 출력
  Serial.print("  Y : ");  // 시리얼 모니터에 “  Y : “출력
  Serial.print(analogRead(joystick_y));  // y값을 읽어와 시리얼 모니터에 출력
  Serial.print("  SW : ");  // 시리얼 모니터에 “  SW : “출력
  if (analogRead(joystick_sw) == 0)  // 조이스틱을 누르면
  {
    Serial.println("ON");  // ON 출력
  }
  else  // 조이스틱을 누르지 않으면
  {
    Serial.println("OFF");  // OFF 출력
  }
  delay(100);  // 0.1초 지연
}

