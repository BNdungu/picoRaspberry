#include <Stepper.h>

const int stepsPerRevolution = 2038;

Stepper myStepper = Stepper(stepsPerRevolution, 0, 2, 1, 3);

void setup() {
}

void loop() {
	myStepper.setSpeed(5);
	myStepper.step(238);
	
	myStepper.setSpeed(15);
	myStepper.step(-538);
}
