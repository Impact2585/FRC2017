/*
 * Robot.cpp
 */
#include "Robot.h"

Robot::Robot() {

}

Robot::~Robot() {

}

void Robot::RobotInit() {

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

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot)


