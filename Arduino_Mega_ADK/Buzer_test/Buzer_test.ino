int speakerpin = 12; 
 
void setup() {
  
}
 
void loop() {
  tone(speakerpin,500,1000);  //500: 음의 높낮이(주파수), 1000: 음의 지속시간(1초)
  delay(2000); 
}
