#include <Servo.h>

Servo testServo;

const int buttonPin = 10;
const int servoPin = 9;
int servoPos = 0;

void setup() {
  pinMode(buttonPin, INPUT);

  testServo.attach(servoPin);
  testServo.write(servoPos);
}

void loop() {

  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    servoPos += 1;
    testServo.write(servoPos);
    delay(3);
  }
}
