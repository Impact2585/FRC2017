#include "TestInputMethod.h"

TestInputMethod::TestInputMethod() : desiredForwardVal(0), finished(false), limitSwitchStatus(false) {

}

TestInputMethod::~TestInputMethod() {

}

double TestInputMethod::getForwardDistance() {
    return desiredForwardVal;
}

double TestInputMethod::getSidewaysDistance() {
    return 0;
}

bool TestInputMethod::toggleDrive() {
    return false;
}

bool TestInputMethod::shootToggle() {
    return false;
}

bool TestInputMethod::intake() {
    return false;
}

bool TestInputMethod::outtake() {
    return false;
}

bool TestInputMethod::toggleBlockHolder() {
    return toggleBlockSystem;
}

bool TestInputMethod::toggleLever() {
    return toggleLeverSystem;
}

void TestInputMethod::setLeverToggle(bool toggle) {
    toggleLeverSystem = toggle;
}

void TestInputMethod::setBlockHolderToggle(bool toggle) {
    toggleBlockSystem = toggle;
}

void TestInputMethod::setDesiredForward(float val) {
    desiredForwardVal = val;
}

void TestInputMethod::setFinished(bool finished) {
    this->finished = finished;
}

bool TestInputMethod::isFinished() {
    return finished;
}

bool TestInputMethod::shiftGears() {
    return false;
}

bool TestInputMethod::getLimitSwitchStatus() {
    return limitSwitchStatus;
}

void TestInputMethod::setLimitSwitchStatus(bool status) {
    limitSwitchStatus = status;
}
