#include "CenterTimedGearDelivery.h"

CenterTimedGearDelivery::CenterTimedGearDelivery(std::shared_ptr<Environment> environ) : TaskChain(environ) {

}

CenterTimedGearDelivery::~CenterTimedGearDelivery() {

}

void CenterTimedGearDelivery::init() {
    addTask(std::make_shared<TimedDriveTask>(environ->getSystems().at(DriveSystem::NAME), 2, true));
    addTask(std::make_shared<TimedDriveTask>(environ->getSystems().at(DriveSystem::NAME), 2, false));
}
