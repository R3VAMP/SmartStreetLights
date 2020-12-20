#include <ESP8266WiFi.h>

/*************** Network Inputs ***************/ 
const char* ssid     = "windows_hotspot";
const char* password = "123swagat";
const char* host = "192.168.43.31"; //replace it with your webhost url
String url;
 WiFiClient client;
void setup() 
{

 
 Serial.begin(115200);   // Initiate a serial communication
 
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.println();
  Serial.println("Welcome...");
  Serial.println();

  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, 80)) {
    Serial.println("connection failed");
    return;
  }
  url = "/tat/update.php?id=1&status=on";
  
  client.print(String("GET /") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
 while(client.available()){
   String line = client.readStringUntil('\r');
   Serial.print(line);
 }
    
  Serial.println();
  Serial.println("closing connection");
  
 } 

void loop() 
{ 
   
}

