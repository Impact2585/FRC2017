#ifndef TEST_TESTTASK_H_
#define TEST_TESTTASK_H_
#include <memory>
#include "EndSignal.h"

#include "../TestInputMethod.h"
#include "../../src/tasks/Task.h"

class TestTask : public Task {
public:
    TestTask(std::shared_ptr<TestInputMethod> input, std::shared_ptr<EndSignal> signal);
    virtual ~TestTask();
    virtual void onStart();
    bool getStarted();
    bool getEnded();
    virtual void execute();
    virtual void onEnd();
    bool getToggleState();
    std::shared_ptr<EndSignal> getEndSignal();
protected:
    virtual bool checkIfFinished();

private:
    std::shared_ptr<TestInputMethod> input;
    bool started;
    bool ended;
    bool toggle;
    std::shared_ptr<EndSignal> endSignal;
};

#endif
