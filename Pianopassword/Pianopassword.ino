#include <SoftwareSerial.h>

#define NOTE_C4  262
#define NOTE_D4  294 
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

SoftwareSerial BTSerial(2, 3);

int speakerPin = 8;
int noteDuration = 250;

int NOTES[8] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
               NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

String note_name[] = { "Do", "Re", "Mi", "Fa", "Sol", "La", "Ti", "Do"};

void setup() {
    Serial.begin(9600);
    BTSerial.begin(9600);
}


void loop() {
    if(BTSerial.available()){             // 블루투스 데이터 수신
      byte data = BTSerial.read();
      if(data >= '1' && data <= '8')      // 범위 내의 값인 경우
      {
         tone(speakerPin, NOTES[data - '1'], noteDuration);   // 음 재생
         Serial.println(note_name[data - '1']);               // 시리얼 모니터 출력
      }
    }
}
