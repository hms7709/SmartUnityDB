int IN1 = 5;
int IN2 = 6;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(IN1, 200);                    // L_motor_L에 0(0V)의 신호를 출력합니다.
  analogWrite(IN2, 0);
  Serial.println("START");
  delay(3000);
  
  analogWrite(IN1, 0);                    // L_motor_L에 0(0V)의 신호를 출력합니다.
  analogWrite(IN2, 200);
  Serial.println("STOP");
  delay(3000);
}
