//buzzer
#define BuzzerPin 6

void setup() {
 pinMode(BuzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(BuzzerPin, OUTPUT);
  delay(1000);
  digitalWrite(BuzzerPin, LOW);
  delay(1000);
}
