//#include <SoftwareSerial.h>
//SoftwareSerial mybluetooth (2, 3);
int red = 9;
int green = 10;
int blue = 11;

void setup() 
{  
 //mybluetooth.begin(9600);
  pinMode (red, OUTPUT); // Red
  pinMode (green, OUTPUT); // Green
  pinMode (blue, OUTPUT); // Blue
}

void Red()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (red, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (red, i);
    delay(10);
  }
}

void Blue()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (blue, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (blue, i);
    delay(10);
  }
}

void Green()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (green, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (green, i);
    delay(10);
  } 
}

void White()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (red, i);
    analogWrite (green, i);
    analogWrite (blue, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (red, i);
    analogWrite (green, i);
    analogWrite (blue, i);
    delay(10);
  }
}

void LightGreen()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (red, i);
    analogWrite (green, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (red, i);
    analogWrite (green, i);
    delay(10);
  }
}

void LightBlue()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (green, i);
    analogWrite (blue, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (green, i);
    analogWrite (blue, i);
    delay(10);
  } 
}

void Purple()
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite (red, i);
    analogWrite (blue, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite (red, i);
    analogWrite (blue, i);
    delay(10);
  } 
}
   
 
void loop() 
{
  Red();
  LightGreen();
  LightBlue();
  Green();
  Blue();
  White();
  Purple();
}
