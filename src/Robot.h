/*
 * Robot.h
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include <sys/socket.h>
#include "systems/DriveSystem.h"
#include <IterativeRobot.h>
#include "executors/Executor.h"
#include "tasks/TaskChain.h"
#include "tasks/taskchains/CenterTimedGearDelivery.h"
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
    std::shared_ptr<CenterTimedGearDelivery> centerGear;
};


#endif /* SRC_ROBOT_H_ */
