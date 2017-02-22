#ifndef SRC_SYSTEMS_GEARBOXSYSTEM_H_
#define SRC_SYSTEMS_GEARBOXSYSTEM_H_

#include "RobotSystem.h"
#include "../RobotMap.h"
#include "../utils/Toggler.h"
#include <memory>

#ifndef TESTING
#include <Timer.h>
#include <Spark.h>
#include <DigitalInput.h>
#endif

struct timedMoveSystem {
	double time;
	bool direction;
	bool moving;
#ifndef TESTING
	std::unique_ptr<frc::Timer> timer;
#else
    double currTime;
#endif
	timedMoveSystem(const double& time) : time(time), direction(false), moving(false) {
#ifndef TESTING
		timer = std::make_unique<frc::Timer>();
#else
        currTime = 0;
#endif
	}

	void checkToggle(bool shouldToggle) {
		if(shouldToggle && !moving) {
			moving = true;
			direction ^= true;
#ifndef TESTING
			timer->Start();
#else
            currTime = 0;
#endif
		}
	}

	bool checkTime(double time) {
#ifndef TESTING
		return timer->Get() < time;
#else
        return currTime < time;
#endif
	}

	bool shouldMove() {
		return moving && checkTime(time);
	}

	void reset() {
		moving = false;
#ifndef TESTING
        timer->Reset();
		timer->Stop();
#endif
	}

};

class GearboxSystem : public RobotSystem {

public:
	GearboxSystem(std::shared_ptr<InputMethod> input);
	virtual ~GearboxSystem();
	virtual void run();
	virtual void stopAllMotors();
	void spinBlockMotor(float speed);
	void spinLeverMotor(float speed);
	const static char *NAME;

	double getSpeedFromInversion(double speed, bool invert);
    struct timedMoveSystem *getLeverSystem();
    struct timedMoveSystem *getBlockHolderSystem();

    float getBlockSpeed();
    float getLeverSpeed();
    
	static constexpr float BLOCK_TIME = 1.0;
	static constexpr float BLOCK_SPEED = 0.1;
	static constexpr float LEVER_TIME = 1.0;
	static constexpr float LEVER_SPEED = 0.1;

private:
	std::unique_ptr<Toggler> blockToggler;
	std::unique_ptr<Toggler> leverToggler;

	struct timedMoveSystem *leverSystem;
	struct timedMoveSystem *blockSystem;
#ifndef TESTING
	std::unique_ptr<Spark> lever;
	std::unique_ptr<Spark> block;
    std::unique_ptr<DigitalInput> limitSwitch;
#endif
    float blockSpeed;
    float leverSpeed;

};

#endif
