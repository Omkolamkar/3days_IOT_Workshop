void setup() {
  // put your setup code here, to run once:
pinMode(D1,OUTPUT);
pinMode(D0,OUTPUT);
pinMode(D3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D0,0);
digitalWrite(D1,1);
digitalWrite(D3,0);
delay(100);
digitalWrite(D3,1);
digitalWrite(D1,0);
digitalWrite(D0,1);
delay(100);
}
