/*
 * Robot.cpp
 */
#include "Robot.h"

Robot::Robot() {
	environ = std::make_shared<Environment>();
	executor = std::make_unique<AutonExecutor>(environ);
}

Robot::~Robot() {

}

void Robot::RobotInit() {

}

void Robot::AutonomousInit() {
	executor.reset(new AutonExecutor(environ));
}

/**
 * Sets the executor to a TeleopExecutor.
 */
void Robot::TeleopInit() {
	executor.reset(new TeleopExecutor(environ));
}

void Robot::DisabledInit() {
	environ->stopAll();
}

void Robot::TeleopPeriodic() {
	executor->execute();
}

void Robot::AutonomousPeriodic() {
	executor->execute();
}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot)



