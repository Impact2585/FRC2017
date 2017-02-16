/*
 * Robot.h
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include <IterativeRobot.h>
#include "executors/Executor.h"
#include "tasks/TaskChain.h"
#include <WPILib.h>
#include <SmartDashboard/SendableChooser.h>
#include "Environment.h"
#include "executors/AutonExecutor.h"
#include "executors/TeleopExecutor.h"

class Robot : public frc::IterativeRobot {
public:
	Robot();
	~Robot();
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
private:
	std::shared_ptr<Environment> environ;
	std::unique_ptr<Executor> executor;
	SendableChooser<TaskChain*> autonChoice;	
};


#endif /* SRC_ROBOT_H_ */
