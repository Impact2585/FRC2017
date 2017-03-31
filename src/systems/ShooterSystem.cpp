#include "ShooterSystem.h"

const char *ShooterSystem::NAME = "SHOOTERSYSTEM";

ShooterSystem::ShooterSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input), shouldShoot(false), shootSpeed(0.5), prevIncP(false), prevDecP(false) {
#ifndef TESTING
    shooter = std::make_unique<Spark>(RobotMap::SHOOTER);
    feeder = std::make_unique<Spark>(RobotMap::FEEDER);
    agitator = std::make_unique<Victor>(RobotMap::AGITATOR);
#endif
    shooterToggler = std::make_unique<Toggler>();
}

ShooterSystem::~ShooterSystem() {

}

void ShooterSystem::run() {
    bool shouldToggle = input->shootToggle();

    bool incSpeed = input->increaseShootSpeed();
    bool decSpeed = input->decreaseShootSpeed();

    if(incSpeed && shootSpeed != 1 && !prevIncP) {
        shootSpeed += 0.1;
    } else if(decSpeed && shootSpeed != 0 && !prevDecP) {
        shootSpeed -= 0.1;
    }

    if(shooterToggler->toggled(shouldToggle)) {
        shouldShoot = !shouldShoot;
    }

    if(shouldShoot) {
        spinAll();
    } else {
        stopAllMotors();
    }

    prevIncP = incSpeed;
    prevDecP = decSpeed;
}

void ShooterSystem::spinShooter(float speed) {
    shooter->Set(speed);
}
void ShooterSystem::spinFeeder(float speed) {
    feeder->Set(speed);
}

void ShooterSystem::spinAll() {
    moveAgitator(LOAD_SPEED);
    spinShooter(shootSpeed);
    spinFeeder(FEEDER_SPEED);
}

void ShooterSystem::moveAgitator(float speed) {
#ifndef TESTING
    agitator->Set(speed);
#endif
}

void ShooterSystem::spinMotors() {
#ifndef TESTING
    shooter->Set(shootSpeed);
    feeder->Set(FEEDER_SPEED);
#endif
}

void ShooterSystem::stopAllMotors() {
    spinShooter(0);
    spinFeeder(0);
    moveAgitator(0);
}
