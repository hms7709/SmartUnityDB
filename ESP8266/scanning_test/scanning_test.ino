#include "ESP8266WiFi.h"
#include <ESP8266WebServer.h>

void scanWiFiList() 
{ 
  int numberOfNetworks = WiFi.scanNetworks(); 
  
  for(int i =0; i < numberOfNetworks; i++)
  { 
    Serial.println(WiFi.SSID(i)); 
  } 
} 
void setup() 
{ 
  // put your setup code here, to run once: 
  Serial.begin(9600); 
  scanWiFiList(); 
} 
 
void loop() 
{ 
  // put your main code here, to run repeatedly: 
}
