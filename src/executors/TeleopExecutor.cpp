/*
 * TeleopExecutor.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */

#include "TeleopExecutor.h"

TeleopExecutor::TeleopExecutor(std::shared_ptr<Environment> environ) : Executor(environ) {

}

TeleopExecutor::~TeleopExecutor() {

}

void TeleopExecutor::execute() {
	for(std::vector<std::unique_ptr<RobotSystem>>::iterator system = systems.begin(); system != systems.end(); ++system) {
		(*system)->run();
	}
}
