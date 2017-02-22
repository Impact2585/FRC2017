/*
 * XboxController.cpp
 */

#include "XboxController.h"

XboxController::XboxController() {
	joystick = std::make_unique<Joystick>(0);
}

XboxController::~XboxController() {

}

/**
 * Gets the value that the driver wants the drivetrain to move forward.
 */
double XboxController::getForwardDistance() {
	return joystick->GetRawAxis(XboxConstants::LEFT_Y_AXIS);
}

/**
 * Gets the sideways power of which the driver wants to turn.
 */
double XboxController::getSidewaysDistance() {
	return joystick->GetRawAxis(XboxConstants::RIGHT_X_AXIS);
}

/**
 * Gets whether the driver wants the drive to invert.
 *
 * @return the state of the drive toggle button.
 */
bool XboxController::toggleDrive() {
	return joystick->GetRawButton(XboxConstants::Y_BUTTON);
}

/**
 * Gets whether the driver wants to toggle the shoot function.
 */
bool XboxController::shootToggle() {
	return joystick->GetRawButton(XboxConstants::X_BUTTON);
}

bool XboxController::intake() {
	return joystick->GetRawButton(XboxConstants::RIGHT_BUMPER);
}

bool XboxController::outtake() {
	return joystick->GetRawButton(XboxConstants::LEFT_BUMPER);
}

bool XboxController::toggleBlockHolder() {
    return joystick->GetRawButton(XboxConstants::A_BUTTON);
}

bool XboxController::toggleLever() {
    return joystick->GetRawButton(XboxConstants::B_BUTTON);
}
