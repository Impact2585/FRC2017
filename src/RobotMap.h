/*
 * RobotMap.h
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

class RobotMap {
public:
	//drive ports
	static constexpr int FRONT_LEFT_DRIVE = 1; //Victor
	static constexpr int REAR_LEFT_DRIVE = 2; //Talon
	static constexpr int FRONT_RIGHT_DRIVE = 3; //Victor
	static constexpr int REAR_RIGHT_DRIVE = 4; //Talon

	static constexpr int INTAKE_MOTOR= 0; //Spark
	static constexpr int AGITATOR = 5; //Victor
	
	static constexpr int SHOOTER_RIGHT = 6; //Spark
	static constexpr int SHOOTER_LEFT = 7; //Spark

	static constexpr int BLOCK_HOLDER = 8; //Spark
	static constexpr int LEVER = 9; //Spark
    
    //digital io
    static constexpr int GEAR_LEVER_LIMIT_SWITCH = 6;
};

#endif
