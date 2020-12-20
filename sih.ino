#include <ESP8266WiFi.h>

/*************** Outputs ***************/  // LOW is OFF; HIGH is ON
int led1 = D0; // choose pin for the LED
int led2 = D6; // choose pin for the LED
int led3 = D7; // choose pin for the LED
int led4 = D8; // choose pin for the LED
//int led5 = D5; // choose pin for the LED
//int led6 = D6; // choose pin for the LED

/*************** Inputs ***************/  //when object output is LOW  when no object output is HIGH
int ir1= D1; // input pin (for Infrared sensor) 
int ir2= D2; // input pin (for Infrared sensor) 
int ir3= D3; // input pin (for Infrared sensor) 
int ir4= D5; // input pin (for Infrared sensor) 
int ldr= A0; // input pin (for LDR sensor) 

int val1,val2,val3,val4; // variable for reading the pin status

/*************** Network Inputs ***************/ 
const char* ssid     = "windows_hotspot"; //ssid name of the hotspot
const char* password = "123swagat"; //password of hotspot
const char* host = "192.168.43.31"; //replace it with your webhost url
String url;
int count=0;
void setup() 
{
  Serial.begin(115200);   // Initiate a serial communication
 
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  
  pinMode (ir1,INPUT);
  pinMode (ir2,INPUT);
  pinMode (ir3,INPUT);
  pinMode (ir4,INPUT);
  pinMode (ldr,INPUT);
  
  digitalWrite(ir1, HIGH); // make all irs off
  digitalWrite(ir2, HIGH); // make all irs off
  digitalWrite(ir3, HIGH); // make all irs off
  digitalWrite(ir4, HIGH); // make all irs off

    
  digitalWrite(led1, LOW); // make all irs off
  digitalWrite(led2, LOW); // make all irs off
  digitalWrite(led3, LOW); // make all irs off
  digitalWrite(led4, LOW); // make all irs off
  
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
  //Serial.print("Netmask: ");
  //Serial.println(WiFi.subnetMask());
  //Serial.print("Gateway: ");
  //Serial.println(WiFi.gatewayIP());
  Serial.println();
  Serial.println("Welcome...");
  Serial.println();

}
void loop() 
{ 
  /*******************   Server Connection Code **********************/
  WiFiClient client;
//  Serial.print("connecting to ");
//  Serial.println(host);
  if (!client.connect(host, 80)) {
    Serial.println("connection failed");
    return;
  }
 /* if (count==0)
  {
    url = "/tat/update.php?id=1&status=on";
  
  client.print(String("GET /") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  count++;}*/
               
//  write ur connection code here
//if (analogRead(ldr)>= 300)
//{
   val1 = digitalRead(ir1); // read input value 
   val2 = digitalRead(ir2); // read input value 
   val3 = digitalRead(ir3); // read input value 
   val4 = digitalRead(ir4); // read input value 
   
   /********************   IR1    ********************/
   
   if (val1 == LOW)                        //D1
   {  
      url = "/tat/update.php?id=1&status=on";
      digitalWrite(led1, HIGH); // turn LED ON  
      client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
      delay(1000); 
      while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
 }
    
//  Serial.println();
//  Serial.println("closing connection");
  } 

   else
   {
    url = "/tat/update.php?id=1&status=off";
    digitalWrite(led1, LOW); // turn LED OFF
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    delay(1000); 
   while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
   } 
   }
   delay(5000);
  /********************   IR2    ********************/
  
   if (val2 == LOW)                           //D2
   {  
      url = "/tat/update.php?id=2&status=on";
      digitalWrite(led2, HIGH); // turn LED ON   
      client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
      delay(1000); 
    /*  while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
 } */
   }
   else
   {
    url = "/tat/update.php?id=2&status=off";
    digitalWrite(led2, LOW); // turn LED OFF
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    delay(1000); 
 /*   while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
 }*/
 } 
delay(5000);
  /********************   IR3    ********************/
  
  if (val3 == LOW)                           //D3
   {  
      url = "/tat/update.php?id=3&status=on";
      digitalWrite(led3, HIGH); // turn LED ON   
      client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
      delay(1000); 
   /*   while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
  } */
   }
   else
   {
    url = "/tat/update.php?id=3&status=oHHff";
    digitalWrite(led3, LOW); // turn LED OFF
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    delay(1000); 
   /* while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
 }*/
   }    
 delay(5000); 
  /********************   IR4    ********************/
  
   if (val4 == LOW)                   //D5
   {  
      url = "/tat/update.php?id=4&status=on";
      digitalWrite(led4, HIGH); // turn LED ON
      client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
      delay(1000); 
    /*  while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);
 } */
   }
   else
   {
    url = "/tat/update.php?id=4&status=off";
    digitalWrite(led4, LOW); // turn LED OFF    
    client.print(String("GET /") + url + " HTTP/1.1\r\n" +"Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
    delay(1000); 
  /*  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
 }*/
   } 
delay(5000);   
  
 /*******************   Server Connection Code **********************/

  //  Serial.print(" Sending Data to Server ");
   // Serial.println();
    /*client.print(String("GET /") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
     delay(1000);*/

 /*********** If u want to see the response  ***************/

/* while(client.available()){
   String line = client.readStringUntil('\r');
   Serial.print(line);
 }
    
//  Serial.println();
//  Serial.println("closing connection");
  */
// } 
 /*else
 { 
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
 }*/
}

