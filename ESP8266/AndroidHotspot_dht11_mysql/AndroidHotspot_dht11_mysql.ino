#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DHT.h>
 
#define PIN_DHT D4
 
const char* ssid = "AndroidHotspot5524";
const char* password = "minsung7709";
String host = "http://192.168.43.248";

const long interval = 5000;
unsigned long previousMillis = 0;

WiFiServer server(80);
WiFiClient client;
HTTPClient http;
DHT DHTsensor(PIN_DHT, DHT11);
 
void setup() {
  DHTsensor.begin();
  
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);   // , password
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("Server started");
}
 
void loop() {
  // 센서값 DB 전송 부분
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    float humidity = DHTsensor.readHumidity();
    float temp = DHTsensor.readTemperature();
    
    String phpHost = host+"/insert.php?temp="+String(temp)+"&humidity="+String(humidity);
    Serial.print("Connect to ");
    Serial.println(phpHost);
    
    http.begin(client, phpHost);
    http.setTimeout(1000);
    int httpCode = http.GET();
   
    if(httpCode > 0) {
      Serial.printf("GET code : %d\n\n", httpCode);

      if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println(payload);
      }
    } 
    else {
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

  float humidity = DHTsensor.readHumidity();
  float temp = DHTsensor.readTemperature();

  client.print("HTTP/1.1 200 OK");
  client.print("Content-Type: text/html\r\n\r\n");
  client.print("<!DOCTYPE HTML>");
  client.print("<html>");
  client.print("<head>"); 
  client.print("<meta charset=\"UTF-8\" http-equiv=\"refresh\" content=\"1\">");
  client.print("<title>DHT senrsor test Webpage</title>");
  client.print("</head>");
  client.print("<body>");
  client.print("<h2>DHT senrsor test Webpage</h2>");
  client.print("<br>");
  client.print("Temperature : ");
  client.print(temp);
  client.print(" °C");
  client.print("<br>");
  client.print("Humidity : ");
  client.print(humidity);
  client.print(" %");
  client.print("</body>");
  client.print("</html>");

  Serial.println("클라이언트 연결 해제");
}
