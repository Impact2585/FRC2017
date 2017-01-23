/*
 * Environment.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */

#include "Environment.h"

Environment::Environment() : input(new XboxController){
	systems.push_back(std::make_unique<DriveSystem>(input));
}

Environment::~Environment() {

}

std::vector<std::unique_ptr<RobotSystem>>& Environment::getSystems() {
	return systems;
}

