#include "TestTask.h"

TestTask::TestTask(std::shared_ptr<TestInputMethod> input, std::shared_ptr<EndSignal> signal) : input(input), started(false), ended(false), toggle(false), endSignal(signal) {

}

TestTask::~TestTask() {

}

void TestTask::onStart() {
    started = true; 
}

void TestTask::execute() {
    toggle ^= true;
}

void TestTask::onEnd() {
    endSignal->setEnded(true);
}

bool TestTask::checkIfFinished() {
    return input->isFinished();
}

bool TestTask::getStarted() {
    return started;
}

bool TestTask::getEnded() {
    return ended;
}

bool TestTask::getToggleState() {
    return toggle;
}

std::shared_ptr<EndSignal> TestTask::getEndSignal() {
    return endSignal;
}
