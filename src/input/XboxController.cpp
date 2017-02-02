/*
 * XboxController.cpp
 */

#include "XboxController.h"

XboxController::XboxController() {
	joystick = std::make_unique<Joystick>(1);
}

XboxController::~XboxController() {

}

/**
 * Gets the value that the driver wants the drivetrain to move forward.
 */
double XboxController::getForwardDistance() {
	return joystick->GetRawAxis(RobotMap::LEFT_Y_AXIS);
}

double XboxController::getSidewaysDistance() {
	return joystick->GetRawAxis(RobotMap::RIGHT_X_AXIS);
}

/**
 * Gets whether the driver wants to shoot.
 */
bool XboxController::shoot() {
	return joystick->GetRawButton(RobotMap::X_BUTTON);
}


