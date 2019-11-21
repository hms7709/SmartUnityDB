int L_motor_L = 5;                             // L_motor_L을 5번핀으로 설정합니다.
int L_motor_R = 6;                             // L_motor_R을 5번핀으로 설정합니다.
int R_motor_L = 9;                             // R_motor_L을 5번핀으로 설정합니다.
int R_motor_R = 10;                            // R_motor_R을 5번핀으로 설정합니다.
void setup() {
  pinMode(L_motor_L, OUTPUT);                  // L_motor_L을 출력모드로 설정합니다.
  pinMode(L_motor_R, OUTPUT);                  // L_motor_R을 출력모드로 설정합니다.
  pinMode(R_motor_L, OUTPUT);                  // R_motor_L을 출력모드로 설정합니다.
  pinMode(R_motor_R, OUTPUT);                  // R_motor_R을 출력모드로 설정합니다.
}

void loop() {
  analogWrite(L_motor_L, 0);                    // L_motor_L에 0(0V)의 신호를 출력합니다.
  analogWrite(L_motor_R, 150);                  // L_motor_R에 150(약3V)의 신호를 출력합니다.
  analogWrite(R_motor_L, 0);                    // R_motor_L에 0(0V)의 신호를 출력합니다.
  analogWrite(R_motor_R, 150);                  // R_motor_R에 150(약 3V)의 신호를 출력합니다.
  delay(3000);                                  // 3초간 대기
  analogWrite(L_motor_L, 150);                  // L_motor_L에 150(약 3V)의 신호를 출력합니다.
  analogWrite(L_motor_R, 0);                    // L_motor_R에 0(0V)의 신호를 출력합니다.
  analogWrite(R_motor_L, 150);                  // R_motor_L에 150(약 3V)의 신호를 출력합니다.
  analogWrite(R_motor_R, 0);                    // R_motor_R에 0(0V)의 신호를 출력합니다.
  delay(3000);                                  // 3초간 대기
}
