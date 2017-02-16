#include "Task.h"

Task::Task() : done(false) {

}

Task::~Task() {

}

void Task::run() {
	if(checkIfFinished()) {
		done = true;
	} else {
		execute();	
	}
}

bool Task::isDone() {
	return done;
}
