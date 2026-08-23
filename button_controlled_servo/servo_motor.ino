#include <Servo.h>

Servo myServo;

const int buttonPin = 2;
const int servoPin = 9;

bool servoAt90 = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {

  bool currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentButtonState == LOW) {

    if (servoAt90 == false) {
      myServo.write(90);
      servoAt90 = true;
    }
    else {
      myServo.write(0);
      servoAt90 = false;
    }
  }

  lastButtonState = currentButtonState;
}