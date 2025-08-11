#define TRIGGER D6   // NodeMCU Pin D6 > TRIGGER
#define ECHO    D7   // NodeMCU Pin D7 > ECHO
 long duration, distance;
void setup() // Code under this setup run once.
{
  Serial.begin (9600);          // Set Baud rate to 9600
  pinMode(TRIGGER, OUTPUT);     // Declaring D6 pin as an output.
  pinMode(ECHO, INPUT);  // Declaring D7 pin as an output.
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  }
 
void loop() // Code under this loop runs forever.
{
 
  
  digitalWrite(TRIGGER, LOW);     // Making TRIGGER LOW.
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, HIGH);    // Making TRIGGER HIGH.
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);     // Making TRIGGER LOW.
  duration = pulseIn(ECHO, HIGH); 
  distance = (duration/2)*0.034300;
  
  Serial.print(distance);
  Serial.println(" Cm");
  delay(1000);  // Some Delay

  if(distance > 20 && distance < 30)
  {
    digitalWrite(D0,1);
    delay(50);
    digitalWrite(D0,0);
    delay(50);
  }
  else if(distance > 10 && distance < 20 )
  {
    digitalWrite(D0,1);
    delay(5);
    digitalWrite(D0,0);
    delay(5);
  }
  else if(distance < 10)
  {
    digitalWrite(D0,1);
  }
}
