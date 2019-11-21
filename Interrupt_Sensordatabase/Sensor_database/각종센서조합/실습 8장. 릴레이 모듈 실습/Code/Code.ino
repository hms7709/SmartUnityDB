#define relay 2  // 릴레이 핀 번호 설정
#define sw 3  // 스위치 핀 번호 설정
void setup()  // 초기화
{
  pinMode(relay, OUTPUT);  // 릴레이 연결 핀 출력설정
  pinMode(sw, INPUT);  // 스위치 연결 핀 입력설정
}
void loop()  // 무한루프
{
  if (digitalRead(sw) == HIGH)  // 스위치가 안 눌리면
  {
    digitalWrite(relay, HIGH);  // 릴레이 HIGH (NO, Nomal Open 연결)
  }
  else  // 스위치가 눌리면
  {
    digitalWrite(relay, LOW);  // 릴레이 LOW (NC Nomal Close 연결)
  }
}

