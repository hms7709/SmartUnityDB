
void setup() {

}

void loop() {
  analogWrite(9, 200); // RED를      55/255 만큼 켭니다.
  analogWrite(10, 200); // GREEN를 55/255 만큼 켭니다.

  analogWrite(11, 200);  // BLUE핀를 55/255 만큼 켭니다.   -> 흰색 출력 (밝기 200) 

 delay(3000);

  analogWrite(9, 0); // RED를 255/255 만큼 켭니다.

  analogWrite(10, 255);  // GREEN를 0/255 만큼 켭니다.

  analogWrite(11, 255);  // BLUE핀를 0/255 만큼 켭니다. -> 빨강색 출력 (밝기 255) 

  delay(3000);

  for(int a = 0; a < 255; a++)
  {
    analogWrite(9, a);   // RED를 a/255 만큼 켭니다.    -> 밝기 조절
    delay(20);
  }
}
