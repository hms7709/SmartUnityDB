void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int a = 0; a < 255; a++)
  {
    analogWrite(9, a);   // RED를 a/255 만큼 켭니다.    -> 밝기 조절
    delay(20);
  }
}

// 꺼진 상태에서 밝아지는 상태로 변함
