/*
 * RobotMap.h
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

class RobotMap {
public:
	//drive ports
	static constexpr int FRONT_LEFT_DRIVE = 1;
	static constexpr int REAR_LEFT_DRIVE = 2;
	static constexpr int FRONT_RIGHT_DRIVE = 3;
	static constexpr int REAR_RIGHT_DRIVE = 4;

	static constexpr int INTAKE_MOTOR= 5;
	
	static constexpr int SHOOTER_RIGHT = 6;
	static constexpr int SHOOTER_LEFT = 7;
};

#endif
