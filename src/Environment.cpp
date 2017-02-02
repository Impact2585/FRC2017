/*
 * Environment.cpp
 */

#include "Environment.h"

/**
 * Constructor that initializes all of the different RobotSystems.
 *
 */
Environment::Environment() : input(new XboxController){
	systems.push_back(std::make_unique<DriveSystem>(input));
}

Environment::~Environment() {

}

/**
 * Gets all of the RobotSystems.
 *
 * @return a reference to a vector containing the RobotSystems.
 */
std::vector<std::unique_ptr<RobotSystem>>& Environment::getSystems() {
	return systems;
}

