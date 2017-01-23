/*
 * Robot.h
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include <IterativeRobot.h>
#include "executors/Executor.h"
#include "Environment.h"
#include "executors/TeleopExecutor.h"

class Robot : public frc::IterativeRobot {
public:
	Robot();
	~Robot();
	void RobotInit() override;
	void DisabledInit() override;
	void AutonomousInit() override;
	void TeleopInit() override;

	void DisabledPeriodic() override;
	void AutonomousPeriodic() override;
	void TeleopPeriodic() override;
private:
	std::shared_ptr<Environment> environ;
	std::unique_ptr<Executor> executor;
};



#endif /* SRC_ROBOT_H_ */
