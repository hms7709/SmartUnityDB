#include <ESP8266WiFi.h>                // WiFI모듈 헤더파일
#include <ESP8266HTTPClient.h>          // 클라이언트 헤더파일       
#include <DHT.h>                        // DHT11 라이브러리 헤더파일
 
#define PIN_DHT D4                      // DHT11 Pin을 D4번으로 설정
 
const char* ssid     = "Smartunity";    // "Wi-Fi ID"
const char* password = "unity1234";     // "비밀번호"
String host = "http://192.168.0.6";     // "Host 주소"
int brightness = A0;                    // 조도센서 핀을 A0로 설정
const long interval = 5000;             // 타이머 인터럽트를 위한 시간 간격 설정
unsigned long previousMillis = 0;       
 
WiFiServer server(80);
WiFiClient client;
HTTPClient http;                        // http 이름으로 HTTPClient 객체 생성
DHT DHTsensor(PIN_DHT, DHT11);
 
void setup() {
  DHTsensor.begin();                    // DHT11 온습도 센서 초기화
  pinMode(brightness, INPUT);           // 조도센서 핀 설정
  Serial.begin(115200);                 // 통신 속도 115200bps
  WiFi.mode(WIFI_STA);                  // WIFI_STA 모드 (다른 기기가 이 모듈을 통하여 인터넷 접속 금지)   
  WiFi.begin(ssid, password);           // begin 메소드를 통한 Wi-Fi 연결
  while (WiFi.status() != WL_CONNECTED) {  
    delay(500);
    Serial.print(".");
  }
  // Wi-Fi 접속 상태 확인
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();      // 접속된 Wi-Fi 아이디와 IP 주소를 시리얼 모니터에 출력
  Serial.println("Server started");
}
 
void loop() {
  // 센서값 DB 전송 부분
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float Humidity = DHTsensor.readHumidity();
    float Temperature = DHTsensor.readTemperature();
    int Cdsvalue = analogRead(brightness);
    String phpHost = host+"/insert.php?Temperature="+String(Temperature)+"&Humidity="+String(Humidity)+"&Cdsvalue="+String(Cdsvalue);
    // 온습도센서값을 PHP 웹서버로 넘겨준다
    Serial.print("Connect to ");
    Serial.println(phpHost);
    
    http.begin(client, phpHost);
    http.setTimeout(3000);     
    int httpCode = http.GET();
   
    if(httpCode > 0) {  // 연결이 성공할 경우
      Serial.printf("GET code : %d\n\n", httpCode);
 
      if(httpCode == HTTP_CODE_OK) {   // 연결이 성공할 경우
        String payload = http.getString();
        Serial.println(payload);
      }
    } 
    else {   // 연결 실패할 경우
      Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
  }
  
  // 웹서버 부분
  client = server.available();
  if(!client) return;
 
  Serial.println("새로운 클라이언트");
  client.setTimeout(5000);
 
  String request = client.readStringUntil('\r');
  Serial.println("request: ");
  Serial.println(request);
 
  while(client.available()) {
    client.read();
  }
 
  float Humidity = DHTsensor.readHumidity();
  float Temperature = DHTsensor.readTemperature();
  int Cdsvalue = analogRead(brightness);
  client.print("HTTP/1.1 200 OK");
  client.print("Content-Type: text/html\r\n\r\n");
  client.print("<!DOCTYPE HTML>");
  client.print("<html>");
  client.print("<head>"); 
  client.print("<meta charset=\"UTF-8\" http-equiv=\"refresh\" content=\"1\">");
  client.print("<title>Sensor Webpage</title>");
  client.print("</head>");
  client.print("<body>");
  client.print("<h2>Sensor Webpage</h2>");
  client.print("Temperature : ");
  client.print(Temperature);
  client.print(" °C");
  client.print("<br>");
  client.print("Humidity : ");
  client.print(Humidity);
  client.print(" %");
  client.print("<br>");
  client.print("CDS VALUES : ");
  client.print(Cdsvalue);
  client.print("</body>");
  client.print("</html>");
 
  Serial.println("클라이언트 연결 해제");
}
