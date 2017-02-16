#ifndef SRC_SYSTEMS_SHOOTERSYSTEM_H_
#define SRC_SYSTEMS_SHOOTERSYSTEM_H_

#include "RobotSystem.h"
#include "../RobotMap.h"
#include <memory>

#ifndef TESTING
#include <Spark.h>
#endif

class ShooterSystem : public RobotSystem {
public:
	ShooterSystem(std::shared_ptr<InputMethod> input);
	virtual ~ShooterSystem();
	virtual void run();
	virtual void zeroAllMotors();
	void spinMotors(float speed);
	const static char *NAME;
private:
#ifndef TESTING
	std::unique_ptr<Spark> motorLeft;
	std::unique_ptr<Spark> motorRight;
#endif
};

#endif
