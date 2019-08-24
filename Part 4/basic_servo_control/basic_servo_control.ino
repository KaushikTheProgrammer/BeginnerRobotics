#include <Servo.h>

Servo testServo;

void setup() {
  // put your setup code here, to run once:
  testServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  testServo.write(90);
  delay(1000);
  testServo.write(0);
  delay(1000);
}
