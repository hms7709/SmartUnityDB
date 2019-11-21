//LK임베디드
int LED_R = 2; // 빨간 LED 
int LED_G = 3; // 초록 LED
int LED_B = 4; // 파란 LED
void setup() { // 초기화              
  pinMode(LED_R, OUTPUT); // 빨간 LED 출력 설정
  pinMode(LED_G, OUTPUT); // 초록 LED 출력 설정
  pinMode(LED_B, OUTPUT); // 파란 LED 출력 설정
}
/*3색 LED의 색을 각각 점멸 후 혼합 점멸한다.*/
void loop() { // 무한루프
  digitalWrite(LED_R, HIGH); // 빨간 LED ON   
  delay(500);                // 0.5초 지연
  digitalWrite(LED_R, LOW);  // 빨간 LED OFF
  delay(500);                // 0.5초 지연
  digitalWrite(LED_G, HIGH); // 초록 LED ON   
  delay(500);                // 0.5초 지연
  digitalWrite(LED_G, LOW);  // 초록 LED OFF
  delay(500);                // 0.5초 지연
  digitalWrite(LED_B, HIGH); // 파란 LED ON   
  delay(500);                // 0.5초 지연
  digitalWrite(LED_B, LOW);  // 파란 LED OFF
  delay(500);                // 0.5초 지연
  digitalWrite(LED_R, HIGH); // 빨간 LED ON
  delay(500);                // 0.5초 지연
  digitalWrite(LED_B, HIGH); // 파란 LED ON   
  delay(500);                // 0.5초 지연
  digitalWrite(LED_G, HIGH); // 초록 LED ON   
  delay(500);                // 0.5초 지연
  digitalWrite(LED_R, LOW);  // 빨간 LED OFF
  delay(500);                // 0.5초 지연
  digitalWrite(LED_B, LOW);  // 파란 LED OFF
  delay(500);                // 0.5초 지연
  digitalWrite(LED_G, LOW);  // 초록 LED OFF
  delay(500);                // 0.5초 지연
}


