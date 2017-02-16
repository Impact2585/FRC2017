#include "TaskChain.h"

TaskChain::TaskChain(std::shared_ptr<Environment> environ) : environ(environ) {

}

TaskChain::~TaskChain() {

}

void TaskChain::run() {
	if(tasks.size() != 0) {
		if(nextTask) {
			currTask = tasks.erase(currTask);
			nextTask = false;
		} else {
			runTask(currTask);
		}
	}
}

void TaskChain::runTask(std::vector<std::shared_ptr<Task>>::iterator task) {
	if((*task)->isDone()) {
		(*task)->onEnd();
	} else {
		(*task)->run();
	}
}
