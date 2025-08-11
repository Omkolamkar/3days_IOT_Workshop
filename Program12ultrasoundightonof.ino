#define TRIGGER D6
#define ECHO    D7
#define LED     D5  // LED connected to pin D5

#define SOUND_SPEED 0.0343  // cm/us

float duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);
}

void loop() {
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
  } else if (distance>10 && distance<30) {
    digitalWrite(D0, HIGH);
    delay(300);               // 200 ms delay
    digitalWrite(D0, LOW);
  } else if (distance>30 && distance<50) {
    digitalWrite(D0, HIGH);
    delay(1000);               // 300 ms delay
    digitalWrite(D0, LOW);
  } else {
    digitalWrite(D0, LOW);   // Turn off if object is far
  }
  delay(500); // Main loop delay for stability
}
