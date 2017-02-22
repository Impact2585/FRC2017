#ifndef SRC_SYSTEMS_SHOOTERSYSTEM_H_
#define SRC_SYSTEMS_SHOOTERSYSTEM_H_

#include "RobotSystem.h"
#include "../RobotMap.h"
#include <memory>
#include "../utils/Toggler.h"

#ifndef TESTING
#include <Spark.h>
#include <Victor.h>
#endif

class ShooterSystem : public RobotSystem {
public:
	ShooterSystem(std::shared_ptr<InputMethod> input);
	virtual ~ShooterSystem();
	virtual void run();
	virtual void stopAllMotors();
	void spinAll();
	void moveAgitator(float speed);
	void spinMotors(float speed);
	const static char *NAME;
	static constexpr float LOAD_SPEED = 0.5;
	static constexpr float SHOOT_SPEED = 0.8;
private:
#ifndef TESTING
	std::unique_ptr<Spark> motorLeft;
	std::unique_ptr<Spark> motorRight;
	std::unique_ptr<Victor> agitator;
#endif
	std::unique_ptr<Toggler> shooterToggler;
	bool shouldShoot;
};

#endif
