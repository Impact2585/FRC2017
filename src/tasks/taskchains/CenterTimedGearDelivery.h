#ifndef SRC_TASKS_TASKCHAINS_CENTERTIMEDGEARDELIVERY_H_
#define SRC_TASKS_TASKCHAINS_CENTERTIMEDGEARDELIVERY_H_
#include "../TaskChain.h"
#include "../TimedDriveTask.h"

class CenterTimedGearDelivery : public TaskChain {
public:
    CenterTimedGearDelivery(std::shared_ptr<Environment> environ);
    ~CenterTimedGearDelivery();
    virtual void initializeTasks();
};

#endif
