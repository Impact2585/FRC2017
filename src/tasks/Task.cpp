#include "Task.h"

Task::Task() : done(false) {

}

Task::~Task() {

}

/**
 * Runs the task. Continously checks if it is finished.
 */
void Task::run() {
	if(checkIfFinished()) {
		done = true;
	} else {
		execute();	
	}
}

/**
 * Gets if the task is done.
 *
 * @return whether the task is done.
 */
bool Task::isDone() {
	return done;
}
