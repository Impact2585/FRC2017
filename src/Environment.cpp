/*
 * Environment.cpp
 */

#include "Environment.h"

/**
 * Constructor that initializes all of the different RobotSystems.
 *
 */
Environment::Environment() : input(new XboxController){
	systems.at(DriveSystem::NAME) = std::make_unique<DriveSystem>(input);
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

