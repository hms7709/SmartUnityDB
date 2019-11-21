
int Buzzer_Pin = 8; 
float Tones[8] = {261.6, 293.7, 329.7, 349.2, 392.0, 440.0, 493.9, 523.3};
//                 도       레    미      파      솔     라     시      도
int Tones_Number; 

void setup(){ 
  pinMode (Buzzer_Pin, OUTPUT);
}

void loop(){ 
  for(Tones_Number = 0; Tones_Number<7; Tones_Number++)
  { 
    tone(Buzzer_Pin, Tones[Tones_Number]); 
    delay(500); 
  }
  
  noTone(Buzzer_Pin);
  
  delay(5000); 
}
