#ifndef SRC_EXECUTORS_AUTONEXECUTOR_H_
#define SRC_EXECUTORS_AUTONEXECUTOR_H_
#include <memory>
#include <vector>
#include "Executor.h"
#include "../tasks/Task.h"
#include "../tasks/TimedDriveTask.h"

class AutonExecutor : public Executor {
public:
	AutonExecutor(std::shared_ptr<Environment> environ);
	virtual ~AutonExecutor();
	virtual void execute();
	void runTask(std::vector<std::shared_ptr<Task>>::iterator task);
private:
	std::vector<std::shared_ptr<Task>> tasks;
	std::vector<std::shared_ptr<Task>>::iterator currTask;

	bool nextTask;
};

#endif /* SRC_EXECUTORS_EXECUTOR_H_ */
