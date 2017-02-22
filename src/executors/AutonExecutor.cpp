#include "AutonExecutor.h"

AutonExecutor::AutonExecutor(std::shared_ptr<Environment> environ, std::shared_ptr<TaskChain> tasks) : Executor(environ) {
    taskChain = tasks;
    taskChain->setup();
}

AutonExecutor::~AutonExecutor() {

}

void AutonExecutor::execute() {
    taskChain->run();
}


