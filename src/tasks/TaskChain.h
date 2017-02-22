
#ifndef SRC_TASKS_TASKCHAIN_H_
#define SRC_TASKS_TASKCHAIN_H_
#include <memory>
#include <vector>
#include "Task.h"

#ifndef TESTING
#include "../Environment.h"
#endif

class TaskChain {
public:

#ifndef TESTING
	TaskChain(std::shared_ptr<Environment> environ);
#else
	TaskChain();
#endif
	~TaskChain();
	void setup();
	virtual void initializeTasks() = 0;
	void run();
	void runTask(std::vector<std::shared_ptr<Task>>::iterator task);
	void addTask(std::shared_ptr<Task> task);
	std::shared_ptr<Task> getCurrentTask();
	//std::vector<std::shared_ptr<Task>>::iterator getCurrentTask();

protected:
	std::vector<std::shared_ptr<Task>>::iterator currTask;
	std::vector<std::shared_ptr<Task>> tasks;
#ifndef TESTING
	std::shared_ptr<Environment> environ;
#endif
	bool nextTask;
	bool started;
};

#endif
