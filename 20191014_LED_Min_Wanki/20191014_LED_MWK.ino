#include <SoftwareSerial.h>

SoftwareSerial mybluetooth (2, 3);      //tx -> 2, rx -> 3

void setup() {
  pinMode (11, OUTPUT);                //Red
  pinMode (10, OUTPUT);                //Green
  pinMode (9, OUTPUT);                 //Blue
  
  mybluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (mybluetooth.available())
  {
    char button = mybluetooth.read();
    Serial.println (button);
      
      if (button == '1')  //Red
    {
      digitalWrite (11, HIGH); 
      digitalWrite (10, LOW);
      digitalWrite (9, LOW);
    }
      
      else if (button == '2')  //Green
    {
      digitalWrite (11, LOW);
      digitalWrite (10, HIGH);
      digitalWrite (9, LOW);
    }
      
      else if (button == '3')  //Blue
    {
      digitalWrite (11, LOW);
      digitalWrite (10, LOW);
      digitalWrite (9, HIGH);
    }
      
      else if (button == '4')  //White
    {
      digitalWrite (11, HIGH);
      digitalWrite (10, HIGH);
      digitalWrite (9, HIGH);
    }

      else if (button == '5')  //Purple
    {
      digitalWrite (11, HIGH);
      digitalWrite (10, LOW);
      digitalWrite (9, HIGH);
    }

      else if (button == '6')  //Sky Blue
    {
      digitalWrite (11, LOW);
      digitalWrite (10, HIGH);
      digitalWrite (9, HIGH);
    }

      else if (button == '7')  //Yellow
    {
      digitalWrite (11, HIGH);
      digitalWrite (10, HIGH);
      digitalWrite (9, LOW);
    } 
      
      else if (button == '0')  //LED Off
    {
      digitalWrite (11, LOW);
      digitalWrite (10, LOW);
      digitalWrite (9, LOW);
    }
  }
}
