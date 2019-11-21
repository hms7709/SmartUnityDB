int totalCount = 0;//엔코더값 저장 변수
int SW = 7;  //로터리 엔코더 핀 
int DT = 6;
int CLK = 5;
int oldDT = LOW;
int oldCLK = LOW;
void setup()  // 초기화
{
 Serial.begin(9600); // 시리얼 통신 초기화
 pinMode(SW, INPUT_PULLUP);  // 로터리 엔코더 SW핀 풀업 입력 설정
 pinMode(DT, INPUT);  // 로터리 DT 방향 입력핀 입력 설정
 pinMode(CLK, INPUT);  // 로터리 CLK 방향 입력핀 입력 설정
}
/*엔코더를 돌리면 값을 표시한다.*/
int nowCnt = 0;
void loop()  // 무한루프
{
 if (LOW == digitalRead(SW))  //만약 스위치가 눌리면
 {
 Serial.println("Switch"); //시리얼 모니터로 "Switch"표시
 delay(200);  // 200ms 지연
 }
 nowCnt = getValue();  // 로터리 엔코더의 값을 받아 변수에 저장
 if (nowCnt != 0)  // 현재값이 0이 아니면
 {
 totalCount += nowCnt;  // 총카운트에 로터리 엔코더 입력값을 가산
 Serial.println(totalCount);  // 시리얼 모니터에 총카운트 출력
 }
}
int getValue()  //로터리 엔코더의 값을 읽어오는 함수
{
 int rValue = 0;
 int A = digitalRead(DT);  // DT 방향값 저장 (돌리면 HIGH, 정지상태LOW)
 int B = digitalRead(CLK);  // CLK 방향값 저장 (돌리면 HIGH, 정지상태 LOW)
 delay(3);  // 3ms 지연
 if (A != oldDT || B != oldCLK)
 {
 if (oldDT == LOW && A == HIGH)
 {
 if (oldCLK == HIGH) rValue = 1;  // CLK 방향으로 움직였다면 카운트 +1
 else rValue = -1;  // DT 방향으로 움직였다면 카운트 -1
 }
 }
 oldDT = A;
 oldCLK = B;
 return rValue;  // 해당값을 return
}

 
