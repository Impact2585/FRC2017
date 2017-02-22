#ifndef TEST_TESTABLETASKCHAIN_H_
#define TEST_TESTABLETASKCHAIN_H_
#include "../../src/tasks/TaskChain.h"
#include "../TestInputMethod.h"
#include "TestTask.h"
#include "EndSignal.h"

class TestableTaskChain : public TaskChain {
public:
    TestableTaskChain(std::shared_ptr<TestInputMethod> input);
    virtual ~TestableTaskChain();
    virtual void initializeTasks();
private:
    std::shared_ptr<TestInputMethod> input;
};


#endif
