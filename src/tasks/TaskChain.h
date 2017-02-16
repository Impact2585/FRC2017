
#ifndef SRC_TASKS_TASKCHAIN_H_
#define SRC_TASKS_TASKCHAIN_H_
#include <memory>
#include <vector>
#include "Task.h"
#include "../Environment.h"

class TaskChain {
public:
	TaskChain(std::shared_ptr<Environment> environ);
	~TaskChain();
	virtual void init() = 0;
	void run();
	void runTask(std::vector<std::shared_ptr<Task>>::iterator task);
private:
	std::vector<std::shared_ptr<Task>> tasks;
	std::vector<std::shared_ptr<Task>>::iterator currTask;
	std::shared_ptr<Environment> environ;
	bool nextTask;
};

#endif
