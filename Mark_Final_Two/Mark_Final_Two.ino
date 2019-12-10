#include <Servo.h>
#include "pitches.h"
#include <Key.h>
#include <Keypad.h>

int relay = 3;
int tru = 0;
int count = 0;
char PW[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {22, 23, 24, 25};
byte colPins[COLS] = {26, 27, 28, 29};
int mistery_buzzer = 8;

char keys[ROWS][COLS] = 
   {{ '1', '2', '3', 'A' }, 
   { '4', '5', '6', 'B' },
   { '7', '8', '9', 'C' }, 
   { '*', '0', '#', 'D' }};

Servo myservo;
int servoPin = 7;
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

unsigned long intervals[] = {5000, 10000, 2000};
unsigned long last[] = {0, 0, 0};
int Liquid_level = 0;
int notouch_water = 12;

void setup()
{
  Serial.begin(9600);
  pinMode (mistery_buzzer, OUTPUT);
  pinMode(notouch_water, INPUT);
  myservo.attach(servoPin);
  myservo.write(90);
  pinMode(relay, OUTPUT);
}

void loop()
{
  char key = mykeypad.getKey();
  
  if (key)
  {
    Serial.println(key);
    if (key == PW[0])
    {
      tone (mistery_buzzer, 262);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[1])
    {
      tone (mistery_buzzer, 294);
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++; 
    }

    if (key == PW[2])
    {
      tone (mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++; 
    }
    
    if (key == PW[3])
    {
      tone (mistery_buzzer, 349);
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[4])
    {
      tone (mistery_buzzer, 392);
      analogWrite(8, 0);
      analogWrite(9, 0);
      analogWrite(10, 255);
      count++;
      tru++;
    }

    if (key == PW[5])
    {
      tone(mistery_buzzer, 440);
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[6])
    {
      tone(mistery_buzzer, 494);
      analogWrite(9, 0);
      analogWrite(10, 0);
      analogWrite(11, 0);
      count++;
      tru++; 
    }

    if (key == PW[7])
    {
      tone(mistery_buzzer, 523);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 0);
      myservo.write(0);
      Serial.println("open the door"); 
      count++;
      tru++;
    }

    if (key == PW[8])
    {
      tone(mistery_buzzer, 392);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[9])
    {
      tone(mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

    if (key == PW[10])
    {
      tone(mistery_buzzer, 294);
      analogWrite(9, 255);
      analogWrite(10, 0);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[11])
    {
      tone(mistery_buzzer, 330);
      analogWrite(9, 255);
      analogWrite(10, 255);
      analogWrite(11, 0);
      count++;
      tru++;
    }

     if (key == PW[12])
    {
      tone(mistery_buzzer, 262);
      myservo.write(90);
      analogWrite(9, 0);
      analogWrite(10, 255);
      analogWrite(11, 255);
      count++;
      tru++;
    }

    if (key == PW[13])
    {
      noTone(mistery_buzzer);
      tru = 0;
      count = 0;
    }
    
    else if (key == '#')
    {
       replay();
    }
  }

   unsigned long now = millis();
      
   if(now - last[0] >= intervals[0])
   {
       last[0] = now;
       Task0();
   }

   if(now - last[1] >= intervals[1])
   {
       last[1] = now;
       Task1();
   }

   if(now - last[2] >= intervals[2])
   {
       last[2] = now;
       Task2();
   }
}

void Task0()
{
   digitalWrite(relay, HIGH);
}

void Task1()
{
   digitalWrite(relay, LOW);
}

void Task2()
{
  Liquid_level = digitalRead(notouch_water);
  Serial.print("Liquid_level = ");
  Serial.println(Liquid_level, DEC);
}

void replay()
{
  tru = 0;
  count = 0;
  Serial.println("password reset");
}
