//RGB LED
#define RLED 5
#define GLED 2
#define BLED 3

void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
}

void loop() {
  analogRead(RLED, 255);
  analogRead(GLED, 0);
  analogRead(BLED, 0);

  analogRead(RLED, 0);
  analogRead(GLED, 255);
  analogRead(BLED, 0);

  analogRead(RLED, 0);
  analogRead(GLED, 0);
  analogRead(BLED, 255);
}
