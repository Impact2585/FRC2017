#include "AutonExecutor.h"

AutonExecutor::AutonExecutor(std::shared_ptr<Environment> environ, std::shared_ptr<TaskChain> tasks) : Executor(environ), tasks(tasks) {

}

AutonExecutor::~AutonExecutor() {

}

void AutonExecutor::execute() {
    tasks->run();
}


