#include <Servo.h>
#include "pitches.h"
#include <Key.h>
#include <Keypad.h>

int tru = 0;
int count = 0;
char PW[16] = {'1', '2', '3', 'A', '4', '5', '6', 'B', '7', '8', '9', 'C', '*', '0', '#', 'D'};
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {34, 35, 36, 37};
byte colPins[COLS] = {38, 39, 40, 41};
int mistery_buzzer = 3;

char keys[ROWS][COLS] = 
   {{ '1', '2', '3', 'A' }, 
   { '4', '5', '6', 'B' },
   { '7', '8', '9', 'C' }, 
   { '*', '0', '#', 'D' }};

Servo myservo;
int servoPin = 7;
Keypad mykeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  pinMode (mistery_buzzer, OUTPUT);
  myservo.attach(7);
  myservo.write(0);
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
      count++;
      tru++;
    }

    if (key == PW[1])
    {
      tone (mistery_buzzer, 294);
      count++;
      tru++; 
    }

    if (key == PW[2])
    {
      tone (mistery_buzzer, 330);
      count++;
      tru++; 
    }
    
    if (key == PW[3])
    {
      tone (mistery_buzzer, 349);
      count++;
      tru++;
    }

    if (key == PW[4])
    {
      tone (mistery_buzzer, 392);
      count++;
      tru++;
    }

    if (key == PW[5])
    {
      tone(mistery_buzzer, 440);
      count++;
      tru++;
    }

    if (key == PW[6])
    {
      tone(mistery_buzzer, 494);
      count++;
      tru++; 
    }

    if (key == PW[7])
    {
      tone(mistery_buzzer, 523);
      myservo.write(180);
      Serial.println("open the door"); 
      count++;
      tru++;
    }

    if (key == PW[8])
    {
      tone(mistery_buzzer, 392);
      count++;
      tru++;
    }

    if (key == PW[9])
    {
      tone(mistery_buzzer, 330);
      count++;
      tru++;
    }

    if (key == PW[10])
    {
      tone(mistery_buzzer, 294);
      count++;
      tru++;
    }

    if (key == PW[11])
    {
      tone(mistery_buzzer, 330);
      count++;
      tru++;
    }

     if (key == PW[12])
    {
      tone(mistery_buzzer, 262);
      myservo.write(0);
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
}

void replay()
{
  tru = 0;
  count = 0;
  Serial.println("password reset");
}




 
