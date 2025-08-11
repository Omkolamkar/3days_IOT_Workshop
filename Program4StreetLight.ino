void setup() {
Serial.begin(9600);
pinMode(A0,INPUT_PULLUP);
pinMode(13,OUTPUT);

}

void loop() {
 
int d = analogRead(A0);
Serial.println(d);
delay(300);
if(d>400)
digitalWrite(13,1);
else
digitalWrite(13,0);
}
