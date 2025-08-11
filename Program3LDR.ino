void setup() {
Serial.begin(9600);
pinMode(A0,INPUT_PULLUP);

}

void loop() {
 
int d = analogRead(A0);
Serial.println(d);
delay(300);
}
