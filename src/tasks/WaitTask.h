#ifndef SRC_TASKS_WAITTASK_H_
#define SRC_TASKS_WAITTASK_H_

#include "Task.h"
#include <memory>
#include <Timer.h>

class WaitTask : public Task {
public:
    WaitTask(float waitTime);
    ~WaitTask();
    virtual void onStart();
    virtual void execute();
    virtual void onEnd();

protected:
    virtual bool checkIfFinished();

private:
    float timeToWait;
    float timeElapsed;
    std::unique_ptr<frc::Timer> timer;
};


#endif
