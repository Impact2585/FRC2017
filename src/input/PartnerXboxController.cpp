/* PartnerXboxController.cpp */ 
#include "PartnerXboxController.h"

PartnerXboxController::PartnerXboxController() {
    joystick1 = std::make_unique<Joystick>(0);
    joystick2 = std::make_unique<Joystick>(1); 
} 
    
PartnerXboxController::~PartnerXboxController() { 

} /**
 * Gets the value that the driver wants the drivetrain to move forward.
 */
double PartnerXboxController::getForwardDistance() {
    return joystick1->GetRawAxis(XboxConstants::LEFT_Y_AXIS);
}

/**
 * Gets the sideways power of which the driver wants to turn.
 */
double PartnerXboxController::getSidewaysDistance() {
    return joystick1->GetRawAxis(XboxConstants::RIGHT_X_AXIS);
}

/**
 * Gets whether the driver wants the drive to invert.
 *
 * @return the state of the drive toggle button.
 */
bool PartnerXboxController::toggleDrive() {
    return joystick1->GetRawButton(XboxConstants::Y_BUTTON);
}

/**
 * Gets whether the driver wants to toggle the shoot function.
 */
bool PartnerXboxController::shootToggle() {
    return joystick2->GetRawButton(XboxConstants::X_BUTTON);
}

bool PartnerXboxController::intake() {
    return joystick1->GetRawButton(XboxConstants::RIGHT_BUMPER);
}

bool PartnerXboxController::outtake() {
    return joystick1->GetRawButton(XboxConstants::LEFT_BUMPER);
}

bool PartnerXboxController::toggleBlockHolder() {
    return joystick2->GetRawButton(XboxConstants::A_BUTTON);
}

bool PartnerXboxController::toggleLever() {
    return joystick2->GetRawButton(XboxConstants::X_BUTTON);
}

/**
 * B for boost
 */
bool PartnerXboxController::shiftGears() {
    return joystick1->GetRawButton(XboxConstants::B_BUTTON);
}

bool PartnerXboxController::shouldWind() {
    return joystick2->GetRawButton(XboxConstants::RIGHT_BUMPER);
}

bool PartnerXboxController::shouldUnwind() {
    return joystick2->GetRawButton(XboxConstants::LEFT_BUMPER);
}

bool PartnerXboxController::increaseShootSpeed() {
    return false;
}

bool PartnerXboxController::decreaseShootSpeed() {
    return false;
}

