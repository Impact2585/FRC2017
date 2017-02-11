#include "Command.h"

Command::Command() : done(false) {

}

Command::~Command() {

}

void Command::run() {
	if(checkIfFinished()) {
		done = true;
	} else {
		execute();	
	}
}

bool Command::isDone() {
	return done;
}
