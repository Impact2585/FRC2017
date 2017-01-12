/*
 * Robot.h
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_
#include <IterativeRobot.h>

class Robot : public frc::IterativeRobot {
public:
	Robot();
	virtual ~Robot();
	void RobotInit() override;
	void DisabledInit() override;
	void AutonomouseInit() override;
	void TeleopInit() override;

	void DisabledPeriodic() override;
	void AutonomousPeriodic() override;
	void TeleopPeriodic() override;

};



#endif /* SRC_ROBOT_H_ */
