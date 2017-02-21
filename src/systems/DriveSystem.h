/*
 * DriveSystem.h
 */

#ifndef SRC_SYSTEMS_DRIVESYSTEM_H_
#define SRC_SYSTEMS_DRIVESYSTEM_H_

#ifndef TESTING
#include <RobotDrive.h>
#include <Talon.h>
#include <Victor.h>
#endif

#include "RobotSystem.h"
#include "../RobotMap.h"
#include "../utils/Toggler.h"

class DriveSystem : public RobotSystem {
public:
	DriveSystem(std::shared_ptr<InputMethod> input);
	virtual ~DriveSystem();
	virtual void run();
	virtual void stopAllMotors();
	void modifyIfInDeadzone(double& val);
	void drive(double forward, double rotation, bool squared);
	void arcadeControl(double desiredForwardValue, double rotation, bool squared);
	static constexpr double RAMP = 0.8;
	static constexpr double MIN_INCREMENT = 0.1;
	static constexpr double DEADZONE = 0.1;
	static const char *NAME;
	double getRotateVal();
	double getCurrentRampForward();
private:
#ifndef TESTING
	std::unique_ptr<RobotDrive> drivetrain;
#endif
	double currentRampForward;
	bool invertDrive;
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

template<typename T> inline T absval(T val) {
	return val > T(0) ? val : -val;
};

#endif /* SRC_SYSTEMS_DRIVESYSTEM_H_ */
