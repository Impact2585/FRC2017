#ifndef SRC_TASKS_TASKCHAINS_CENTERTIMEDGEARDELIVERY_H_
#define SRC_TASKS_TASKCHAINS_CENTERTIMEDGEARDELIVERY_H_
#include "../TaskChain.h"
#include "../ReleaseGearTask.h"
#include "../WaitTask.h"
#include "../TimedDriveTask.h"

class CenterTimedGearDelivery : public TaskChain {
public:
    CenterTimedGearDelivery(std::shared_ptr<Environment> environ);
    ~CenterTimedGearDelivery();
    virtual void initializeTasks();
    std::shared_ptr<RobotSystem> getSystem(std::string name);
};

#endif
