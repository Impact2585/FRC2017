#include "GearboxSystem.h"

GearboxSystem::GearboxSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input) {
	blockTimer = std::make_unique<Timer>();
	blockTimer->Start();
	leverTimer = std::make_unique<Timer>();
	leverTimer->Start();
}

GearboxSystem::~GearboxSystem() {

}

void GearboxSystem::run() {
	blockToggle = input->toggleDrive();
	leverToggle = input->toggleDrive();
	if(blockToggle) {
		//ignore input if the time is less than time needed to complete action
		if((blockTimer->Get() - blockLastPressed) + blockBufferTime > blockTurnTime) {
			turnBlock(blockTurnTime);
		}
	}
	if(leverToggle) {
		if((leverTimer->Get() - leverLastPressed) + leverBufferTime > leverTurnTime) {
			turnLever(leverTurnTime);
		}
	}
}


void GearboxSystem::turnBlock(double time) {
	blockLastPressed = blockTimer->Get();
	blockTimer->Reset();
	spinBlockMotor(0.1);
}

void GearboxSystem::turnLever(double time) {
	leverLastPressed = leverTimer->Get();
	leverTimer->Reset();
	spinLeverMotor(0.1);
}

void GearboxSystem::spinBlockMotor(float speed) {

}

void GearboxSystem::spinLeverMotor(float speed) {
	if(leverIsBack) {
		moveFoward();
	} else {
		moveBackward();
	}
}

void GearboxSystem::zeroAllMotors() {

}
