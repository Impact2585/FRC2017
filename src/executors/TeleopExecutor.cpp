/*
 * TeleopExecutor.cpp
 */

#include "TeleopExecutor.h"

TeleopExecutor::TeleopExecutor(std::shared_ptr<Environment> environ) : Executor(environ) {

}

TeleopExecutor::~TeleopExecutor() {

}

/**
 * Runs through all the different systems.
 * This should be called periodically in Robot.cpp during teleop.
 */
void TeleopExecutor::execute() {
    for(auto& entry : systems) {
        (entry.second)->run();
    }
}
