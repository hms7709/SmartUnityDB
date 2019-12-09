
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid     = "AndroidHotspot5524";
const char* password = "minsung7709";
const char* host = "http://192.168.43.248/http.html";
 
WiFiClient client;
HTTPClient http;
 
void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connect to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  Serial.printf("Connect to %s\n", host);
  http.begin(client, host);
  http.setTimeout(1000);
  int httpCode = http.GET();
 
  if(httpCode > 0) {
    Serial.printf("GET code : %d\n\n", httpCode);
    
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    }
  } 
  else {
    Serial.printf("GET failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
 
  delay(5000);
}
