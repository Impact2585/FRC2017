#include "TaskChainTest.h"

TaskChainTest::TaskChainTest() : currToggle(false) {
    input = std::make_shared<TestInputMethod>();
    tasks = std::make_unique<TestableTaskChain>(input);
    tasks->init();
    //tasks.add(std::shared_ptr<TimedDriveTask>(drive, 5000)); 
    //tests.add(std::shared_ptr<TimedDriveTask>(drive, 3000));
    TEST_ADD(TaskChainTest::testInitTask);
    TEST_ADD(TaskChainTest::testRunTask);
    TEST_ADD(TaskChainTest::testSwitchTask);
}

TaskChainTest::~TaskChainTest() {

}

void TaskChainTest::testInitTask() {
    tasks->run();    
    TEST_ASSERT(static_cast<TestTask*>(tasks->getCurrentTask().get())->getStarted() == true);
    //use == for verbosity
    TEST_ASSERT(getAndCheckToggle() == true);
    updateSignal();
    TEST_ASSERT(currSignal->hasEnded() == false);
}

void TaskChainTest::testRunTask() {
    tasks->run();
    TEST_ASSERT(getAndCheckToggle() == true);
    TEST_ASSERT(currSignal->hasEnded() == false);
    tasks->run();
    TEST_ASSERT(getAndCheckToggle() == true);
    //TEST_ASSERT(static_cast<TestTask*>(tasks->getCurrentTask().get())->getEnded() == false);
    TEST_ASSERT(currSignal->hasEnded() == false);
}

void TaskChainTest::testSwitchTask() {
    input->setFinished(true);
    tasks->run();
    TEST_ASSERT(getAndCheckToggle() == false);
    //TEST_ASSERT(static_cast<TestTask*>(tasks->getCurrentTask().get())->getEnded() == true);
    TEST_ASSERT(currSignal->hasEnded() == true);
    
    //only switches after first run
    input->setFinished(false);
    tasks->run();
    tasks->run();
    updateSignal();
    resetToggle();
    TEST_ASSERT(static_cast<TestTask*>(tasks->getCurrentTask().get())->getStarted() == true);
    TEST_ASSERT(getAndCheckToggle() == true);
    TEST_ASSERT(currSignal->hasEnded() == false);    

    //test if no null pointers
    input->setFinished(true);
    tasks->run();
    tasks->run();
}

void TaskChainTest::resetToggle() {
    //task has switched so it should default back to false
    currToggle = false;
}
void TaskChainTest::updateSignal() {
    currSignal = static_cast<TestTask*>(tasks->getCurrentTask().get())->getEndSignal();
}

/**
 * Updates the currToggle and checks to see if currToggle was toggled by the TestTask.
 * Checks if the execute method was run in TestTask.
 *
 * @return whether the current state of the toggle and previous toggle match.
 */
bool TaskChainTest::getAndCheckToggle() {
    bool prev = currToggle;
    currToggle = static_cast<TestTask*>(tasks->getCurrentTask().get())->getToggleState();
    return prev != currToggle; 
}
