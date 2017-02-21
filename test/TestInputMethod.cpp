#include "TestInputMethod.h"

TestInputMethod::TestInputMethod() : desiredForwardVal(0), finished(false) {

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

bool TestInputMethod::shoot() {
	return false;
}

bool TestInputMethod::intake() {
	return false;
}

bool TestInputMethod::outtake() {
	return false;
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
