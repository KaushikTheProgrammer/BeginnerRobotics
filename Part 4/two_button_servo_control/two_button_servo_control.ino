#include <Servo.h>

Servo testServo;

const int increaseButtonPin = 10;
const int decreaseButtonPin = 11;
const int servoPin = 9;
int servoPos = 0;

void setup() {
  pinMode(increaseButtonPin, INPUT);
  pinMode(decreaseButtonPin, INPUT);

  testServo.attach(servoPin);
  testServo.write(servoPos);

  Serial.begin(9600);
}

void loop() {

  int increaseState = digitalRead(increaseButtonPin);
  int decreaseState = digitalRead(decreaseButtonPin);

  if (increaseState == HIGH && servoPos < 180) {
    servoPos += 1;
  } else if (decreaseState == HIGH && servoPos > 0) {
    servoPos -= 1;
  }

  testServo.write(servoPos);
  delay(3);
  Serial.println(servoPos);
}
