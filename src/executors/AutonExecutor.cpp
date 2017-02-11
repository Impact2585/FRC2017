#include "AutonExecutor.h"

AutonExecutor::AutonExecutor(std::shared_ptr<Environment> environ) : Executor(environ), nextCommand(false) {
	std::shared_ptr<Command> command( new TimedDriveCommand(environ->getSystems(), 500));
	commands.push_back(command);
	currCommand = commands.begin();
}

AutonExecutor::~AutonExecutor() {

}

void AutonExecutor::runCommand(std::vector<std::shared_ptr<Command>>::iterator command) {
	if((*command)->isDone()) {
		(*command)->onEnd();
		nextCommand = true;
	} else { 
		(*command)->run();
	}
}

void AutonExecutor::execute() {
	if(commands.size() != 0) {
		if(nextCommand) {
			currCommand = commands.erase(currCommand);
			nextCommand = false;
		} else {
			runCommand(currCommand);
		}
	}
}
