/*
 * ParallelTask.h
 */
#include "ParallelTask.h"

ParallelTask::ParallelTask(std::initializer_list<Task*> commandList) {
	for(auto command : commandList) {
		commands.push_back(std::unique_ptr<Task>(command));
	}
}

ParallelTask::~ParallelTask() {

}

void ParallelTask::onStart() {
	for(auto& command : commands) {
		command->onStart();
	}
}

void ParallelTask::execute() {
	for(auto& command : commands) {
		if(!command->isDone())
			command->execute();
	}
}

void ParallelTask::onEnd() {
	for(auto& command : commands) {
		command->onEnd();
	}
}

bool ParallelTask::checkIfFinished() {
	for(auto& command : commands) {
		if(!command->isDone()) 
			return false;
	}
	return true;
}
