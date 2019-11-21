const uint8_t LED1 = 10;

// 매 루프마다 millis()라는 함수를 사용해서 현재 아두이노의 시간이
// 몇 ms인지 파악하고, 그 시간이 우리가 원하는 지정된 시간 이상이 되면 특정 함수를 실행.
// 단 millis()는 조금만 시간이 지나도 숫자가 매우 커지기 때문에,
// 가장 큰 길이의 데이터 형태인 long을 사용하고,
// 음수의 시간데이터는 나오지 않기 때문에 unsigned를 붙혀 데이터의 가용범위를 늘린다.
// LED 1개를 깜빡이는 코드를 millis()로 구현

// Set timer
unsigned long pre_time = 0;
unsigned long cur_time = 0;


// Set LED status
boolean state_led1 = 0;

// Set duration
const int duration = 1000;

void setup() 
{
  pinMode(LED1, OUTPUT);

  // Initialize previous counter time
  pre_time = millis();
}

void loop() {
  //Update current time in every loop
  cur_time = millis();

  // If time gap between previous and current goes over the duration,
  // run digital write!
  if(cur_time - pre_time >= duration)
  {
    //Change the boolean state.
    state_led1 = ~state_led1;

    digitalWrite(LED1, state_led1);

    // Update previous counter time.
    pre_time = cur_time;
  }

  else
  {
    //Do something...
  }
}
