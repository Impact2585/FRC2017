/*
 * RobotMap.h
 */

#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_

class RobotMap {
public:
    //drive ports
    static constexpr int LEFT_DRIVE = 1; //Victor Victor
    static constexpr int RIGHT_DRIVE = 3; //Victor Victor

    static constexpr int LIFT = 2; //Talon Talon

    static constexpr int INTAKE_MOTOR= 0; //Victor
    static constexpr int AGITATOR = 5; //Victor
    
    static constexpr int SHOOTER= 6; //Spark
    static constexpr int FEEDER = 7; //Spark

    static constexpr int BLOCK_HOLDER = 8; //Spark
    static constexpr int LEVER = 9; //Spark
    
    //digital io
    static constexpr int GEAR_LEVER_LIMIT_SWITCH = 6;
    static constexpr int BALL_SHIFTER_PORT = 7;
};

#endif
