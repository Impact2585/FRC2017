/*
 * DriveSystem.h
 */

#ifndef SRC_SYSTEMS_DRIVESYSTEM_H_
#define SRC_SYSTEMS_DRIVESYSTEM_H_
#include <RobotDrive.h>
#include "RobotSystem.h"
#include "../RobotMap.h"
#include "../utils/Toggler.h"

class DriveSystem : public RobotSystem {
public:
	DriveSystem(std::shared_ptr<InputMethod> input);
	virtual ~DriveSystem();
	void run();
	void modifyIfInDeadzone(double& val);
	void drive(double forward, double rotation, bool squared);
	void arcadeControl(double desiredForwardValue, double rotation, bool squared);
	static constexpr double RAMP = 0.6;
	static constexpr double MIN_INCREMENT = 0.1;
	static constexpr double DEADZONE = 0.15;
	static const char *NAME;
private:
	std::unique_ptr<RobotDrive> drivetrain;
	double currentRampForward;
	bool invertDrive;
	bool invertInput;
	std::unique_ptr<Toggler> invertDriveToggler;
};

/**
 * Checks and returns the sign of val.
 *
 * @param T the value to check the sign of.
 * @return the sign of val.
 */
template<typename T> inline int signum(T val) {
	return (val > T(0)) - (T(0) < val);
};



#endif /* SRC_SYSTEMS_DRIVESYSTEM_H_ */
