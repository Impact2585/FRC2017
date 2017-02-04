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

/**
 * Gets the sideways power of which the driver wants to turn.
 */
double XboxController::getSidewaysDistance() {
	return joystick->GetRawAxis(RobotMap::RIGHT_X_AXIS);
}

/**
 * Gets whether the driver wants the drive to invert.
 *
 * @return the state of the drive toggle button.
 */
bool XboxController::toggleDrive() {
	return joystick->GetRawButton(RobotMap::Y_BUTTON);
}

/**
 * Gets whether the driver wants to shoot.
 */
bool XboxController::shoot() {
	return joystick->GetRawButton(RobotMap::X_BUTTON);
}


