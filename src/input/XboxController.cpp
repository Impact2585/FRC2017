/*
 * XboxController.cpp
 *
 *  Created on: Jan 23, 2017
 *      Author: joshua
 */

#include "XboxController.h"

XboxController::XboxController() {
	joystick = std::make_unique<Joystick>(1);
}

XboxController::~XboxController() {

}

double XboxController::getForwardDistance() {
	return joystick->GetRawAxis(1);
}

double XboxController::getSidewaysDistance() {
	return joystick->GetRawAxis(3);
}

bool XboxController::shoot() {
	return joystick->GetRawButton(3);
}


