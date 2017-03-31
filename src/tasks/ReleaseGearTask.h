#ifndef SRC_TASKS_RELEASEGEARTASK_H_
#define SRC_TASKS_RELEASEGEARTASK_H_
#include "Task.h"
#include <map>
#include "../systems/GearboxSystem.h"

class ReleaseGearTask : public Task {
public:
    ReleaseGearTask(std::shared_ptr<RobotSystem> system);
    ~ReleaseGearTask();
    virtual void onStart();
    virtual void execute();
    virtual void onEnd();
    GearboxSystem* getSystem();

protected:
    virtual bool checkIfFinished();

private:
    std::shared_ptr<RobotSystem> gear;
    std::shared_ptr<InputMethod> input;
};


#endif
