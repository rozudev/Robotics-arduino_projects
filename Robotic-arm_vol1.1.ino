#include <Servo.h>
#include <Stepper.h>

Servo servo3; // Gripper
Servo servo2; // Middle joint
Servo servo1; // Lower joint

const int stepsPerRevolution = 2048;
Stepper motor(stepsPerRevolution, 4, 5, 6, 7);

void setup() {

servo1.attach(8);
servo2.attach(9);
servo3.attach(10);
motor.setSpeed(5);

}

void loop() {

// Reset to starting position
servo1.write(0);
servo2.write(0);
servo3.write(0);
delay(3000);

// Open the gripper
for (int angle = 0; angle <= 45; angle++) {
  servo3.write(angle);
  delay(25);
}

delay(1000);

// Lower the middle joint
for (int angle = 0; angle <= 90; angle++) {
  servo2.write(angle);
  delay(25);
}

delay(1000);

// Lower the bottom joint
for (int angle = 0; angle <= 90; angle++) {
  servo1.write(angle);
  delay(25);
}

delay(1000);

// Close the gripper
for (int angle = 45; angle >= 0; angle--) {
  servo3.write(angle);
  delay(25);
}

delay(1000);

// Raise the bottom joint
for (int angle = 90; angle >= 0; angle--) {
  servo1.write(angle);
  delay(25);
}

delay(1000);

// Raise the middle joint
for (int angle = 90; angle >= 0; angle--) {
  servo2.write(angle);
  delay(25);
}

delay(1000);


// Rotate the base with the object
motor.step(512);
delay(1000);

// Place the object

// Lower the middle joint
for (int angle = 0; angle <= 90; angle++) {
  servo2.write(angle);
  delay(25);
}

delay(1000);

// Lower the bottom joint
for (int angle = 0; angle <= 90; angle++) {
  servo1.write(angle);
  delay(25);
}

delay(1000);

// Open the gripper to release the object
for (int angle = 0; angle <= 45; angle++) {
  servo3.write(angle);
  delay(25);
}

delay(1000);


// Return to the starting position

servo1.write(0);
servo2.write(0);

// Rotate the base back to its original position
motor.step(-512);

delay(3000);

}