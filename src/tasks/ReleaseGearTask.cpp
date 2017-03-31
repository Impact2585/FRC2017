#include "ReleaseGearTask.h"

ReleaseGearTask::ReleaseGearTask(std::shared_ptr<RobotSystem> system) {
    gear = system;
    input = getSystem()->getInput();
}

ReleaseGearTask::~ReleaseGearTask() {

}

GearboxSystem *ReleaseGearTask::getSystem() {
    return static_cast<GearboxSystem*>(gear.get());
}

void ReleaseGearTask::onStart() {
    input->setBlockHolderToggler(true);
}

void ReleaseGearTask::execute() {
    getSystem()->run();
    input->setBlockHolderToggler(false);
}

void ReleaseGearTask::onEnd() {
    getSystem()->stopAllMotors();
}

bool ReleaseGearTask::checkIfFinished() {
    return !getSystem()->getBlockHolderSystem()->shouldMove();
}
