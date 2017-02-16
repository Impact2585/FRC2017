/*
 * Environment.cpp
 */

#include "Environment.h"

/**
 * Constructor that initializes all of the different RobotSystems.
 */
Environment::Environment() : input(new XboxController){
	systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(DriveSystem::NAME, std::make_shared<DriveSystem>(input)));
	systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(IntakeSystem::NAME, std::make_shared<IntakeSystem>(input)));
}

Environment::~Environment() {

}

/**
 * Gets all of the RobotSystems and their unique names.
 *
 * @return a reference to a map containing the RobotSystems and names.
 */
std::map<std::string, std::shared_ptr<RobotSystem>>& Environment::getSystems() {
	return systems;
}

/**
 * Stops all systems.
 */
void Environment::stopAll() {
	for(auto& entry : systems) {
		(entry.second)->stopAllMotors();
	}
}
