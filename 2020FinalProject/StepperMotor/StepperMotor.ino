//StepperMotor
#include <AFMotor.h>

AF_DCMotor motor(3);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Motor test!");
  motor.setSpeed(200);  // turn on motor
  motor.run(RELEASE);
}

void loop() {
  uint8_t i;

  Serial.print("tick");

  motor.run(FORWARD);
  for (i = 0; i < 255; i++) {
    motor.setSpeed(i);
    delay(10);
  }

  for (i = 255; i != 0; i--) {
    motor.setSpeed(i);
    delay(10);
  }

  Serial.print("tock");

  /*motor.run(BACKWARD);
    for (i=0; i<255; i++) {
    motor.setSpeed(i);
    delay(10);
    }

    for (i=255; i!=0; i--) {
    motor.setSpeed(i);
    delay(10);
    }


    Serial.print("tech");
    motor.run(RELEASE);
    delay(1000);
  */
}
