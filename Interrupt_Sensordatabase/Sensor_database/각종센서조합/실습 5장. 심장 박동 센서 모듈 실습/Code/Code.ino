int sensorPin = A0;  // 센서 입력 핀
double alpha = 0.75;  // 센서 관련 변수 설정
int period = 100;  // 센서 측정 주기 설정
void setup ()  // 초기화
{
  Serial.begin (9600);  // 시리얼 통신 설정
}
/* 심장 박동 센서 모듈의 값을 시리얼 모니터로 표시한다. */
void loop ()  // 무한루프
{
  static double oldValue = 0;  // 이전 값 저장 변수
  int rawValue = analogRead (sensorPin);  // 센서에 아날로그값을 읽어와서
                                       // rawValue에 저장
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  Serial.print (rawValue);  //시리얼 모니터로 rawValue의 값을 출력
  Serial.print (",");
  Serial.println (value);  //시리얼 모니터로 연산한 값인 value의 값을 출력
  oldValue = value;
  delay (period);
}

