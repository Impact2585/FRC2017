#include "LiftSystem.h"

const char *LiftSystem::NAME = "LIFTSYSTEM";

LiftSystem::LiftSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input) {
    lift = std::make_unique<Talon>(RobotMap::LIFT);
}

LiftSystem::~LiftSystem() {

}

void LiftSystem::windLift(float speed) {
    lift->Set(speed);
}

void LiftSystem::run() {
    bool wind = input->shouldWind();
    bool unwind = input->shouldUnwind();
    if(wind && !unwind) {
        windLift(SPEED);
    } else if(unwind && !wind) {
        windLift(-SPEED);
    } else {
        windLift(0);
    }
}

void LiftSystem::stopAllMotors() {
    windLift(0);
}
