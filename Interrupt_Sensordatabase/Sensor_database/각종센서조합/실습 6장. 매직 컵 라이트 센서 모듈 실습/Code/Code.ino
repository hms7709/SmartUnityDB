int Led_Apin = 4;  // 센서의 L을 D4
int Led_Bpin = 6;  // 센서의 L을 D6
int Sensor_A = 5;  // 센서의 S을 D5
int Sensor_B = 7;  // 센서의 S을 D7
int input_A;  // 센서 값을 읽어올 변수
int input_B;  // 센서 값을 읽어올 변수
int brightness_A = 0;  // LED의 밝기를 조절할 변수
int brightness_B = 0;  // LED의 밝기를 조절할 변수
void setup()  // 초기화
{
  pinMode(Led_Apin, OUTPUT);  // LED핀 출력 설정
  pinMode(Led_Bpin, OUTPUT);  // LED핀 출력 설정
  pinMode(Sensor_A, INPUT_PULLUP);  // 센서 핀 입력 풀업 설정
  pinMode(Sensor_B, INPUT_PULLUP);  // 센서 핀 입력 풀업 설정
}
/* 기울여진 센서쪽 LED가 서서히 켜지고 서서히 꺼진다. */
void loop()  // 무한루프
{
  input_A = digitalRead(Sensor_A);  // 센서의 값을 읽어온다
  input_B = digitalRead(Sensor_B);  // 센서의 값을 읽어온다
  if (input_A == HIGH && brightness_A < 255)  // 센서 값이 HIGH이고 센서 밝기 값이 255보다 작으면
    brightness_A++;  // 밝기 증가
  if (input_A == LOW && brightness_A > 0)  // 센서 값이 LOW이고 센서 밝기 값이 0보다 크면
    brightness_A--;  // 밝기 감소
  if (input_B == HIGH && brightness_B < 255)  // 센서 값이 HIGH이고 센서 밝기 값이 255보다 작으면
    brightness_B++;  // 밝기 증가
  if (input_B == LOW && brightness_B > 0)  // 센서 값이 LOW이고 센서 밝기 값이 0보다 크면
    brightness_B--;  // 밝기 감소
  analogWrite(Led_Apin, brightness_A);  // LED 밝기를 PWM으로 조절한다
  analogWrite(Led_Bpin, brightness_B);  // LED 밝기를 PWM으로 조절한다
  delay(20);  // 0.02초 지연
}

