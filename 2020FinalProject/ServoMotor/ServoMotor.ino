//Servo motor
#include <Servo.h>
Servo myservo_F;
Servo myservo_B;
#define SM_F 9
#define SM_B 10

void setup() {
  myservo_F.attach(SM_F);
  myservo_B.attach(SM_B);
}

void loop() {
  myservo_F.write(0);
  delay(1000);
  myservo_B.write(0);
  delay(1000);
}
