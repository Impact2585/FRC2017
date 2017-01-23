/*
 * DriveSystem.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */

#include "DriveSystem.h"
#include <Talon.h>

DriveSystem::DriveSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input), currentRampForward(0) {
	drivetrain = std::make_unique<RobotDrive>(new Talon(1), new Talon(2), new Talon(3), new Talon(4));
}

DriveSystem::~DriveSystem() {

}

void DriveSystem::drive(double forward, double rotation, bool squared) {
	drivetrain->ArcadeDrive(forward, rotation, squared);
}

void DriveSystem::arcadeControl(double desiredForwardValue, double rotateValue, bool squared) {
	if(desiredForwardValue != 0) {
		double change = desiredForwardValue - currentRampForward;
		currentRampForward = abs(change) > MIN_INCREMENT ? currentRampForward + change * RAMP : desiredForwardValue;
	} else {
		currentRampForward = 0;
	}

	drive(currentRampForward, rotateValue, squared);
}

/**
 * Sets val to 0 if the absolute value of it is below 0.
 *
 */
void DriveSystem::modifyIfInDeadzone(double& val) {
	val = abs(val) <= DEADZONE ? 0 : val;
}

/**
 * Called by the teleopexecutor.
 * Gets input from the inputmethod and drives based on that input.
 */
void DriveSystem::run() {
	double desiredForwardValue = input->getForwardDistance();
	double desiredRotateValue = input->getSidewaysDistance();
	modifyIfInDeadzone(desiredForwardValue);
	modifyIfInDeadzone(desiredRotateValue);
	arcadeControl(desiredForwardValue, desiredRotateValue, true);
}


