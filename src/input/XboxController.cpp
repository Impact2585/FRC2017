
#include "XboxController.h"

XboxController::XboxController() {
    joystick1 = std::make_unique<Joystick>(0);
}

XboxController::~XboxController() {

}

double XboxController::getForwardDistance() {
    return joystick1->GetRawAxis(XboxConstants::LEFT_Y_AXIS);
}

double XboxController::getSidewaysDistance() {
    return joystick1->GetRawAxis(XboxConstants::RIGHT_X_AXIS);
}

bool XboxController::toggleDrive() {
    return joystick1->GetRawButton(XboxConstants::X_BUTTON) && !joystick1->GetRawButton(XboxConstants::B_BUTTON);
}

bool XboxController::shootToggle() {
    return joystick1->GetRawButton(XboxConstants::A_BUTTON) && !joystick1->GetRawButton(XboxConstants::B_BUTTON);
}
    
bool XboxController::intake() {
    return joystick1->GetRawButton(XboxConstants::LEFT_BUMPER);
}

bool XboxController::outtake() {
    return joystick1->GetRawButton(XboxConstants::RIGHT_BUMPER);
}

bool XboxController::toggleBlockHolder() {
    return toggleBlock || (joystick1->GetRawButton(XboxConstants::A_BUTTON) && joystick1->GetRawButton(XboxConstants::B_BUTTON));
}

bool XboxController::toggleLever() {
    return joystick1->GetRawButton(XboxConstants::X_BUTTON) && joystick1->GetRawButton(XboxConstants::B_BUTTON);
}

bool XboxController::shiftGears() {
    return joystick1->GetRawButton(XboxConstants::B_BUTTON) && !joystick1->GetRawButton(XboxConstants::X_BUTTON) && !joystick1->GetRawButton(XboxConstants::A_BUTTON);

}

bool XboxController::shouldWind() {
    return joystick1->GetRawAxis(XboxConstants::RIGHT_TRIGGER) != 0;
}

bool XboxController::shouldUnwind() {
    return joystick1->GetRawAxis(XboxConstants::LEFT_TRIGGER) != 0;
}

bool XboxController::increaseShootSpeed() {
    return joystick1->GetRawButton(XboxConstants::START_BUTTON);
}

bool XboxController::decreaseShootSpeed() {
    return joystick1->GetRawButton(XboxConstants::BACK_BUTTON);
}

