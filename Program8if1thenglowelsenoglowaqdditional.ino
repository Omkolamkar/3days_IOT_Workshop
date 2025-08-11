#include <ESP8266WiFi.h>  // Header file 
#include <WiFiClient.h>   // Header file
#include <ThingSpeak.h>   // Header file

WiFiClient client;   // Creates a client that can connect to to a specified internet IP address

void setup()         // Code under this setup run once.
{
//i = 0;
pinMode(D0,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
Serial.begin(9600);        // Sets the data rate in bits per second (baud) for serial data transmission
ThingSpeak.begin(client); 

  WiFi.disconnect();
  delay(1000);
   WiFi.begin("realmext","om12345678");              //("Wifi Name","Wifi Password")
  while ((!(WiFi.status() == WL_CONNECTED)))
   { 
    delay(300);
    Serial.print(".");
   }
   Serial.println("");
  Serial.println("Connected to WiFi");         
}


void loop()           // Code under this loop runs forever.
{
   int i = ThingSpeak.readIntField(3017973,1,"WV07SMTEW5XQDL9U");  
   Serial.println(i);
   if(i==1){
   digitalWrite(D0,1);
   digitalWrite(D1,1);
   digitalWrite(D2,1);}
   else
   if(i==0){
   digitalWrite(D0,0);
   digitalWrite(D1,0);
   digitalWrite(D2,0);}
}
