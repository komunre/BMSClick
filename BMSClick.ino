#include <Joystick.h>

Joystick_ joystick;

int states[10];

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 2; i < 12; i++) {
    getButtonState(i);
  }
  delay(10);
}

void getButtonState(int pin) {
  int currState = !digitalRead(pin);
  if (currState != states[pin - 2]) {
    joystick.setButton(pin - 2, currState); 
    states[pin - 2] = currState;
  }
}
