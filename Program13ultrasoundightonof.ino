// including the library of DHT11 temperature and humidity sensor
#include <ESP8266WiFi.h>  // Header File
#include <WiFiClient.h>   // Header File
#include <ThingSpeak.h>   // Header File
 int  i = 5; 
 //int Led1 = 16 ;           //Led1 is Attached to GPIO 
  WiFiClient client;

void setup()  
{
 
  Serial.begin(9600);
  ThingSpeak.begin(client);
  delay(700); 
  
  // Connect to WiFi network  
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("realmext","om12345678");
  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
  
  {  
   delay(500);  
   Serial.print(".");  
  }    
} 
 Serial.println("");  
  Serial.println("WiFi connected");  
} 
void loop()   
{
    ThingSpeak.writeField(3017973, 2, i, "VKSLWD09BUMA4Q63");  
   delay(15000);
       // ThingSpeak will only accept updates every 10 seconds.  
    delay(5000);
    i++;
    }
