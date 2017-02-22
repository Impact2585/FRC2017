#include "IntakeSystem.h"

const char *IntakeSystem::NAME = "INTAKESYSTEM";

/**
 * Constructor for the IntakeSystem that sets the input method.
 *
 * @param input the input method to set.
 */
IntakeSystem::IntakeSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input) {
#ifndef TESTING
	motor= std::make_unique<Spark>(RobotMap::INTAKE_MOTOR);
#endif

}

IntakeSystem::~IntakeSystem() {

}

/**
 * Method that is continuously run from the teleopexecutor.
 */
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

/**
 * Stops the intake motor.
 */
void IntakeSystem::stopAllMotors() {
	spinMotor(0);
}

/**
 * Sets the intake motor to speed.
 *
 * @param speed the speed to set.
 */
void IntakeSystem::spinMotor(float speed) {
#ifndef TESTING
	motor->Set(speed);
#endif
}
