#include "TaskChain.h"
#include <stdio.h>

/**
 * Constructor that sets the environment.
 *
 * @param environ the environment to set.
 */
#ifndef TESTING
TaskChain::TaskChain(std::shared_ptr<Environment> environ) : environ(environ), nextTask(false) {
#else
TaskChain::TaskChain() : nextTask(false), started(false) {
#endif

}

TaskChain::~TaskChain() {

}

void TaskChain::setup() {
    initializeTasks();
    currTask = tasks.begin();
}

void TaskChain::run() {
	if(tasks.size() != 0) {
		if(nextTask) {
			currTask = tasks.erase(currTask);
			nextTask = false;
            started = false;
		} else {
			runTask(currTask);
            started = true;
		}
	}
}

void TaskChain::runTask(std::vector<std::shared_ptr<Task>>::iterator task) {
    if(!started) {
        (*task)->onStart();
    }

    (*task)->run();

	if((*task)->isDone()) {
		(*task)->onEnd();
        nextTask = true;
	} 
}

/**
 * Adds a task to the vector of tasks.
 *
 * @param task the task to add.
 */
void TaskChain::addTask(std::shared_ptr<Task> task) {
    tasks.push_back(task);
}

/**
 * Gets the task that the iterator is currently on.
 *
 * @return a shared pointer to the current task.
 */
std::shared_ptr<Task> TaskChain::getCurrentTask() {
    return *currTask;
}
