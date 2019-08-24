#include <Servo.h>

Servo base;
Servo uarm;
Servo gripper;

int pos = 85;
int pos2 = 91;
int pos3 = 0;

int baseR = 0;
int baseL = 0;
int uarmR = 0;
int uarmL = 0;
int gripperO = 0;
int gripperC = 0;

void setup() {

  base.attach(10);
  uarm.attach(11);
  gripper.attach(12);

  Serial.begin(9600);

  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

  base.write(84);
  uarm.write(90);
  gripper.write(0);

}

void loop() {
  baseR = digitalRead(4);
  baseL = digitalRead(5);
  uarmR = digitalRead(6);
  uarmL = digitalRead(7);
  gripperO = digitalRead(8);
  gripperC = digitalRead(9);


  if ((baseR == HIGH) && (pos < 160))
  {
    pos += 1;
    Serial.println(pos);
    base.write(pos);
    delay(10);
  }

  if ((baseL == HIGH) && (pos > 5))
  {
    pos -= 1;
    Serial.println(pos);
    base.write(pos);
    delay(10);
  }

  if ((uarmR == HIGH) && (pos2 < 170)) {
    pos2 += 1;
    Serial.println(pos2);
    uarm.write(pos2);
    delay(10);
  }

  if ((uarmL == HIGH) && (pos2 > 5)) {
    pos2 -= 1;
    Serial.println(pos2);
    uarm.write(pos2);
    delay(10);
  }

  if ((gripperO == HIGH) && (pos3 <= 165)) {
    pos3 += 1;
    Serial.println(pos3);
    gripper.write(pos3);
    delay(10);
  }

  if ((gripperC == HIGH) & (pos3 > 0)) {
    pos3 -= 1;
    Serial.println(pos3);
    gripper.write(pos3);
    delay(10);
  }

}
