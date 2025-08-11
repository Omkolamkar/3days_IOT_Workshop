// including the library of DHT11 temperature and humidity sensor
#include <ESP8266WiFi.h>  // Header File
#include <WiFiClient.h>   // Header File
#include <ThingSpeak.h>   // Header File
 int  i = 5; 
 //int Led1 = 16 ;           //Led1 is Attached to GPIO 
  WiFiClient client;
#define TRIGGER D6
#define ECHO    D7
#define LED     D5  // LED connected to pin D5

#define SOUND_SPEED 0.0343  // cm/us

float duration, distance;


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

  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);
} 
void loop()   
{
  

    // Trigger ultrasonic pulse
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  // Read echo duration and calculate distance
  duration = pulseIn(ECHO, HIGH);
  distance = (duration / 2.0) * SOUND_SPEED;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED control based on distance
  if (distance <= 10) {
    digitalWrite(D0, HIGH);  // Instant on
    delay(100);               // Short blink
    digitalWrite(D0, LOW);
  } else if (distance <= 40) {
    digitalWrite(D0, HIGH);
    delay(200);               // 200 ms delay
    digitalWrite(D0, LOW);
  } else if (distance <= 50) {
    digitalWrite(D0, HIGH);
    delay(300);               // 300 ms delay
    digitalWrite(D0, LOW);
  } else {
    digitalWrite(D0, LOW);   // Turn off if object is far
  }
  
  ThingSpeak.writeField( 3017973  , 2, distance, "VKSLWD09BUMA4Q63");  
   delay(15000);
       // ThingSpeak will only accept updates every 10 seconds.  
    delay(5000);

  delay(500); // Main loop delay for stability

    }
