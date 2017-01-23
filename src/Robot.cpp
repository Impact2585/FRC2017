/*
 * Robot.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: joshua
 */
#include "Robot.h"

Robot::Robot() {

}

Robot::~Robot() {

}

void Robot::AutonomousInit() {

}

/**
 * Sets the executor to a TeleopExecutor.
 */
void Robot::TeleopInit() {
	executor.reset(new TeleopExecutor(environ));
}

void Robot::DisabledInit() {

}

void Robot::TeleopPeriodic() {
	executor->execute();
}

void Robot::AutonomousPeriodic() {

}

START_ROBOT_CLASS(Robot)


