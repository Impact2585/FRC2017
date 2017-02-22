#include "ShooterSystem.h"

const char *ShooterSystem::NAME = "SHOOTERSYSTEM";

ShooterSystem::ShooterSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input), shouldShoot(false) {
#ifndef TESTING
	motorLeft = std::make_unique<Spark>(RobotMap::SHOOTER_LEFT);
	motorRight = std::make_unique<Spark>(RobotMap::SHOOTER_RIGHT);
	motorRight->SetInverted(true);
	agitator = std::make_unique<Victor>(RobotMap::AGITATOR);
#endif
	shooterToggler = std::make_unique<Toggler>();
}

ShooterSystem::~ShooterSystem() {

}

void ShooterSystem::run() {
	bool shouldToggle = input->shootToggle();
	if(shooterToggler->toggled(shouldToggle)) {
		shouldShoot = !shouldShoot;
    }

	if(shouldShoot) {
		spinAll();
	} else {
        stopAllMotors();
    }
}

void ShooterSystem::spinAll() {
	moveAgitator(LOAD_SPEED);
	spinMotors(SHOOT_SPEED);
}
void ShooterSystem::moveAgitator(float speed) {
#ifndef TESTING
    agitator->Set(speed);
#endif
}

void ShooterSystem::spinMotors(float speed) {
#ifndef TESTING
	motorLeft->Set(speed);
	motorRight->Set(speed);
#endif
}

void ShooterSystem::stopAllMotors() {
	spinMotors(0);
    moveAgitator(0);
}
