#include <IRremote.h> // 적외선 송수신을 하기 위한 라이브러리 호출
int RECV_PIN = 11; // 적외선 수신과 연결된 핀 선언(!1번)
IRrecv irrecv(RECV_PIN); // IRrecev 개체를 하나 생성
decode_results results; // 수신받은 자료 저장
void setup()  // 초기화
{
  Serial.begin(9600);  //시리얼 통신 설정
  irrecv.enableIRIn();
}
/*적외선 수신값을 받아서 시리얼 모니터로 표시한다.*/
void loop() {  // 무한루프
  if (irrecv.decode(&results)) {  // 적외선 수신받았을 경우
    Serial.println(results.value, HEX); // 받은 값을 16진수로 출력한다.
    irrecv.resume(); 
  }
}
