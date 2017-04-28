#include "WaitTask.h"

WaitTask::WaitTask(float time) : timeToWait(time), timeElapsed(0) {
    timer = std::make_unique<Timer>();
}

WaitTask::~WaitTask() {

}

void WaitTask::onStart() {
    timer->Start();
}

void WaitTask::execute() {
    timeElapsed = timer->Get();
}

void WaitTask::onEnd() {

}

bool WaitTask::checkIfFinished() {
    return timeElapsed >= timeToWait;
}
