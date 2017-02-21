#ifndef SRC_EXECUTORS_AUTONEXECUTOR_H_
#define SRC_EXECUTORS_AUTONEXECUTOR_H_
#include <memory>
#include <vector>
#include "Executor.h"
#include "../tasks/Task.h"
#include "../tasks/TaskChain.h"

class AutonExecutor : public Executor {
public:
	AutonExecutor(std::shared_ptr<Environment> environ, std::shared_ptr<TaskChain> tasks);
	virtual ~AutonExecutor();
	virtual void execute();
private:
    std::shared_ptr<TaskChain> tasks;
};

#endif /* SRC_EXECUTORS_EXECUTOR_H_ */
