#include <ESP8266WiFi.h>

 const char* ssid = "UplusNet533";//무선 공유기 id로 수정
 const char* password = "4000019269";//무선 공유기 비빌번호

 int ledPin = 2; //
 
 WiFiServer server(80);

 void setup() {
   Serial.begin(115200);
   delay(10);

   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, HIGH);

   // Set WiFi to station mode and disconnect from an AP if it was previously connected
   WiFi.mode(WIFI_STA);
   WiFi.disconnect();
   delay(100);

   Serial.println("Setup done");

   // Connect to WiFi network
   Serial.println();
   Serial.println();
   Serial.print("Connecting to ");
   Serial.println(ssid);

   WiFi.begin(ssid, password);

   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("WiFi connected");

   // Start the server
   server.begin();
   Serial.println("Server started");

   // Print the IP address
   Serial.print("Use this URL to connect: ");
   Serial.print("http://");
   Serial.print(WiFi.localIP());
   Serial.println("/");

 }

 void loop() {
  
   WiFiClient client = server.available(); // Check if a client has connected
   if (!client) {
     return;
   }

   Serial.println("new client");
   while(!client.available())  {  // Wait until client sends data
     delay(1);
   }
  
   String request = client.readStringUntil('\r'); // Read the first line of the request
   Serial.println(request);
   client.flush();

   // Match the request

   int value = LOW;
   if (request.indexOf("/LED=ON") != -1)  {
     digitalWrite(ledPin, LOW);
     value = HIGH;
   }
   if (request.indexOf("/LED=OFF") != -1)  {
     digitalWrite(ledPin, HIGH);
     value = LOW;
   }

   client.println("HTTP/1.1 200 OK");  // Return the response
   client.println("Content-Type: text/html");
   client.println("");             //  do not forget this one
   client.println("<!DOCTYPE HTML>");
   client.println("<html>");
   client.println("<body>");
    client.print("Led pin is now: ");
      if(value == HIGH) {
          client.print(" oｎ");
        }
        else {
          client.print("Off");
        }  
   client.println("<br><br>");
   client.println("<a href=\"/LED=ON\"\"><button>Turn on </button></a>");
   client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />"); 
   client.println("</body>");
   client.println("</html>");

   delay(1);
  
   Serial.println("Client disonnected");
   Serial.println("");
 }
