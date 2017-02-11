#ifndef SRC_EXECUTORS_AUTONEXECUTOR_H_
#define SRC_EXECUTORS_AUTONEXECUTOR_H_
#include <memory>
#include <vector>
#include "Executor.h"
#include "../commands/Command.h"
#include "../commands/TimedDriveCommand.h"

class AutonExecutor : public Executor {
public:
	AutonExecutor(std::shared_ptr<Environment> environ);
	virtual ~AutonExecutor();
	virtual void execute();
	void runCommand(std::vector<std::shared_ptr<Command>>::iterator command);
	//void runCommand(boost::ptr_vector<Command>::iterator command);
private:
	std::vector<std::shared_ptr<Command>> commands;
	std::vector<std::shared_ptr<Command>>::iterator currCommand;
	//boost::ptr_vector<Command> commands;
	//boost::ptr_vector<Command>::iterator currCommand;
	bool nextCommand;
};

#endif /* SRC_EXECUTORS_EXECUTOR_H_ */
