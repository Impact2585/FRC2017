#ifndef SRC_COMMANDS_PARALLELCOMMAND_H_
#define SRC_COMMANDS_PARALLELCOMMAND_H_

#include "Command.h"
#include <memory>
#include <vector>

class ParallelCommand : public Command{
public:
	ParallelCommand(std::vector<std::unique_ptr<Command>> commands);
	virtual ~ParallelCommand();
	virtual void onStart();
	virtual void execute();
	virtual void onEnd();
protected:
	virtual bool checkIfFinished();
private:
	//boost::ptr_vector<Command> commands;
	std::vector<std::unique_ptr<Command>> commands;
	
};

#endif

