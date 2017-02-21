#ifndef TEST_TASKCHAINTEST_H_
#define TEST_TASKCHAINTEST_H_
#include <cpptest-assert.h>
#include <cpptest-suite.h>
#include <memory>

#include "TestableTaskChain.h"
#include "TestTask.h"
#include "../TestInputMethod.h"
#include "EndSignal.h"

class TaskChainTest : public Test::Suite {
public:
    TaskChainTest();
    ~TaskChainTest();
    
private:
    void testInitTask();
    void testRunTask();
    void testSwitchTask();
    bool getAndCheckToggle();
    void resetToggle();
    void updateSignal();
    std::unique_ptr<TestableTaskChain> tasks;
    std::shared_ptr<TestInputMethod> input;
    std::shared_ptr<EndSignal> currSignal;
    bool currToggle;
};

#endif
