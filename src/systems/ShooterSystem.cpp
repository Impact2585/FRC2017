#include "ShooterSystem.h"

ShooterSystem::ShooterSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input) {
#ifndef TESTING
	motorLeft = std::make_unique<Spark>(RobotMap::SHOOTER_LEFT);
	motorRight = std::make_unique<Spark>(RobotMap::SHOOTER_RIGHT);
	motorRight->SetInverted(true);
#endif
}

ShooterSystem::~ShooterSystem() {

}

void ShooterSystem::run() {

}

void ShooterSystem::spinMotors(float speed) {
#ifndef TESTING
	motorLeft->Set(speed);
	motorRight->Set(speed);
#endif
}

void ShooterSystem::zeroAllMotors() {
	spinMotors(0);
}
