int led = 13;       // LED 핀 번호 13
int buzzer = 6;     // BUZZER 핀 번호 6
int flame = 2;      // 불꽃감지 센서 핀 번호 2
int state = 0;      // 불꽃감지 센서의 상태 값 저장 변수
 
void setup() {
  pinMode(led, OUTPUT);    // LED를 출력으로 설정
  pinMode(buzzer, OUTPUT); // BUZZER를 출력으로 설정
  pinMode(flame, INPUT);   // 불꽃 감지 센서를 입력으로 설정
  Serial.begin(9600);      // 시리얼 통신, 속도는 9600
}
 
void loop() {
  state = digitalRead(flame);   // 불꽃 감지 센서값 입력받음
 
  digitalWrite(led, LOW);       // 초기 LED값을 0FF로 설정해주기
  noTone(buzzer);               // 초기에 BUZZER를 출력하지 않기.
  
  if (state == 0){              // 불꽃감지 센서의 값이 0일때(불꽃이 감지 되었을 때)
    Serial.println("ON");       // 시리얼 통신에 센서값 출력해 주기.
    digitalWrite(led, HIGH);    // LED ON
    tone(buzzer, 500, 100);     // 500 - 음의 높낮이, 100 - 부저 지속 시간
    delay(100);                
  }
  else {                        // 불꽃감지 센서의 값이 1일때 (불꽃이 감지 되지 않았을 때)    
    Serial.println("OFF");      // 시리얼 통신에 센서값 출력해 주기.
    digitalWrite(led, LOW);     // LED OFF
    noTone(buzzer);             // BUZZER OFF
  }
  delay(100);
}
