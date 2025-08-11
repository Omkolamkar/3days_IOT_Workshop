void setup() {
  // put your setup code here, to run once:
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,1);
digitalWrite(12,0);
delay(50);
digitalWrite(13,0);
digitalWrite(12,1);
delay(50);

}
