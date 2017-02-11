#include "ParallelCommand.h"

ParallelCommand::ParallelCommand(std::vector<std::unique_ptr<Command>> transfer) : commands(transfer) {
	onStart();
}

ParallelCommand::~ParallelCommand() {

}

void ParallelCommand::onStart() {
	for(auto& command : commands) {
		command->onStart();
	}
}

void ParallelCommand::execute() {
	for(auto& command : commands) {
		if(!command->isDone())
			command->execute();
	}
}

void ParallelCommand::onEnd() {
	for(auto& command : commands) {
		command->onEnd();
	}
}

bool ParallelCommand::checkIfFinished() {
	for(auto& command : commands) {
		if(!command->isDone()) 
			return false;
	}
	return true;
}
