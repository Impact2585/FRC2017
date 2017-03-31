/*
 * Environment.cpp
 */

#include "Environment.h"

/**
 * Constructor that initializes all of the different RobotSystems.
 */
Environment::Environment() : input(new XboxController){
    /** Add all the various systems. */
    systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(DriveSystem::NAME, std::make_shared<DriveSystem>(input)));
    systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(IntakeSystem::NAME, std::make_shared<IntakeSystem>(input)));
    systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(GearboxSystem::NAME, std::make_shared<GearboxSystem>(input)));
    systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(ShooterSystem::NAME, std::make_shared<ShooterSystem>(input)));
    systems.insert( std::pair<std::string, std::shared_ptr<RobotSystem>>(LiftSystem::NAME, std::make_shared<LiftSystem>(input)));
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
