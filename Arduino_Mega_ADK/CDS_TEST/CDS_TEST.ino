void setup() {
  Serial.begin(9600); // 시리얼 통신을 시작, 통신 속도는 9600
}

void loop() {

  int a = analogRead(A0); // 정수형 변수 a를 선언하고 A0핀에 입력되는 신호를 대입

  Serial.println(a);  // 시리얼 모니터에 a를 출력
  delay(500);    // 0.5초 대기

}
