#include "IntakeSystem.h"

const char *IntakeSystem::NAME = "INTAKESYSTEM";

IntakeSystem::IntakeSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input) {
#ifndef TESTING
	motor= std::make_unique<Talon>(RobotMap::INTAKE_MOTOR);
#endif

}

IntakeSystem::~IntakeSystem() {

}

void IntakeSystem::run() {
	bool outtake = input->outtake();
	bool intake = input->intake();
	if(intake && !outtake) {
		spinMotor(INTAKE_SPEED);
	} else if(outtake && !intake) {
		spinMotor(-INTAKE_SPEED);
	} else {
		spinMotor(0);
	}
}

void IntakeSystem::stopAllMotors() {
	spinMotor(0);
}

void IntakeSystem::spinMotor(float speed) {
#ifndef TESTING
	motor->Set(speed);
#endif
}
