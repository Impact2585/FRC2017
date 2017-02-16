#include "AutonExecutor.h"

AutonExecutor::AutonExecutor(std::shared_ptr<Environment> environ) : Executor(environ), nextTask(false) {
	tasks.push_back(std::shared_ptr<Task>(new TimedDriveTask(environ->getSystems(), 500)));
	currTask = tasks.begin();
}

AutonExecutor::~AutonExecutor() {

}

void AutonExecutor::runTask(std::vector<std::shared_ptr<Task>>::iterator task) {
	if((*task)->isDone()) {
		(*task)->onEnd();
		nextTask = true;
	} else { 
		(*task)->run();
	}
}


void AutonExecutor::execute() {
	if(tasks.size() != 0) {
		if(nextTask) {
			currTask = tasks.erase(currTask);
			nextTask = false;
		} else {
			runTask(currTask);
		}
	}
}


