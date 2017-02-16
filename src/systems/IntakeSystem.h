
#ifndef SRC_SYSTEMS_INTAKESYSTEM_H_
#define SRC_SYSTEMS_INTAKESYSTEM_H_

#include "RobotSystem.h"

#ifndef TESTING
#include <Talon.h>
#endif

#include "../RobotMap.h"
#include "../utils/Toggler.h"


class IntakeSystem : public RobotSystem {
public:
	IntakeSystem(std::shared_ptr<InputMethod> input);
	virtual ~IntakeSystem();
	virtual void run();
	virtual void stopAllMotors();
	void spinMotor(float speed);
	static constexpr float INTAKE_SPEED = 0.2;
	static const char *NAME;
private:

#ifndef TESTING
	std::unique_ptr<Talon> motor;
#endif

};
#endif
