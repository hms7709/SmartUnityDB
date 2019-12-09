#include <SoftwareSerial.h>

int humiLED = 8;
int Tx = 10;
int Rx = 11;
SoftwareSerial BTSerial(Tx, Rx); // 5V
int yardLED[] = {22, 23, 24, 25, 26, 27, 28, 29}; // 5V   
int fenceLED[] = {30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};  // 12V

void setup() {
  pinMode(yardLED[0], OUTPUT);
  pinMode(yardLED[1], OUTPUT);
  pinMode(yardLED[2], OUTPUT);
  pinMode(yardLED[3], OUTPUT);
  pinMode(yardLED[4], OUTPUT);
  pinMode(yardLED[5], OUTPUT);
  pinMode(yardLED[6], OUTPUT);
  pinMode(yardLED[7], OUTPUT);
  pinMode(fenceLED[0], OUTPUT);
  pinMode(fenceLED[1], OUTPUT);
  pinMode(fenceLED[2], OUTPUT);
  pinMode(fenceLED[3], OUTPUT);
  pinMode(fenceLED[4], OUTPUT);
  pinMode(fenceLED[5], OUTPUT);
  pinMode(fenceLED[6], OUTPUT);
  pinMode(fenceLED[7], OUTPUT);
  pinMode(fenceLED[8], OUTPUT);
  pinMode(fenceLED[9], OUTPUT);
  pinMode(fenceLED[10], OUTPUT);
  pinMode(humiLED, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
  bufferPosition = 0;
}

void loop() {
  if (BTSerial.available()) {
     byte data = BTSerial.read();
     Serial.write(BTSerial.read());
     buffer[bufferPosition++] = data;

     if (data == 'c') // 울타리 LED ON
     {
        digitalWrite(fenceLED[0], HIGH);
        digitalWrite(fenceLED[1], HIGH);
        digitalWrite(fenceLED[2], HIGH);
        digitalWrite(fenceLED[3], HIGH);
        digitalWrite(fenceLED[4], HIGH);
        digitalWrite(fenceLED[5], HIGH);
        digitalWrite(fenceLED[6], HIGH);
        digitalWrite(fenceLED[7], HIGH);
        digitalWrite(fenceLED[8], HIGH);
        digitalWrite(fenceLED[9], HIGH);
        digitalWrite(fenceLED[10], HIGH);
     }

     else if (data == 'C')  // 울타리 LED OFF
     {
        digitalWrite(fenceLED[0], LOW);
        digitalWrite(fenceLED[1], LOW);
        digitalWrite(fenceLED[2], LOW);
        digitalWrite(fenceLED[3], LOW);
        digitalWrite(fenceLED[4], LOW);
        digitalWrite(fenceLED[5], LOW);
        digitalWrite(fenceLED[6], LOW);
        digitalWrite(fenceLED[7], LOW);
        digitalWrite(fenceLED[8], LOW);
        digitalWrite(fenceLED[9], LOW);
        digitalWrite(fenceLED[10], LOW);
     }
     
     else if (data == 'd')  // 현관등 LED ON
     {
        digitalWrite(yardLED[0], HIGH);
        digitalWrite(yardLED[1], HIGH);
        digitalWrite(yardLED[2], HIGH);
        digitalWrite(yardLED[3], HIGH);
        digitalWrite(yardLED[4], HIGH);
        digitalWrite(yardLED[5], HIGH);
        digitalWrite(yardLED[6], HIGH);
        digitalWrite(yardLED[7], HIGH);
     }
     
     else if (data == 'D')  // 현관등 LED OFF
     {
        digitalWrite(yardLED[0], LOW);
        digitalWrite(yardLED[1], LOW);
        digitalWrite(yardLED[2], LOW);
        digitalWrite(yardLED[3], LOW);
        digitalWrite(yardLED[4], LOW);
        digitalWrite(yardLED[5], LOW);
        digitalWrite(yardLED[6], LOW);
        digitalWrite(yardLED[7], LOW);
     }       
  }
}
