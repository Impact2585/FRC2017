#include "CenterTimedGearDelivery.h"

CenterTimedGearDelivery::CenterTimedGearDelivery(std::shared_ptr<Environment> environ) : TaskChain(environ) {

}

CenterTimedGearDelivery::~CenterTimedGearDelivery() {

}

std::shared_ptr<RobotSystem> CenterTimedGearDelivery::getSystem(std::string name) {
    return environ->getSystems().at(name);
}

void CenterTimedGearDelivery::initializeTasks() {
    addTask(std::make_shared<TimedDriveTask>(getSystem(DriveSystem::NAME), 0.7, 0, 2));
    //addTask(std::make_shared<ReleaseGearTask>(getSystem(GearboxSystem::NAME)));
    addTask(std::make_shared<WaitTask>(2));
    currTask = tasks.begin();
}
