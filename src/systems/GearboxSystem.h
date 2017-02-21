#include "RobotSystem.h"
#include "../RobotMap.h"
#include <memory>
#include <Timer.h>
#include <ctime>

#include <Spark.h>

class GearboxSystem : public RobotSystem {
public:
	GearboxSystem(std::shared_ptr<InputMethod> input);
	virtual ~GearboxSystem();
	virtual void run();
	virtual void zeroAllMotors();
	void spinBlockMotor(float speed);
	void spinLeverMotor(float speed);
	const static char *NAME;
	void turnBlock(double time);
	void turnLever(double time);
	static const double blockTurnTime = 3.0;
	static const double blockBufferTime = 0.3;
	static const double leverTurnTime = 3.0;
	static const double leverBufferTime = 0.3;
private:
	std::unique_ptr<frc::Timer> blockTimer;
	std::unique_ptr<frc::Timer> leverTimer;
	bool blockToggle = false;
	bool leverToggle = false;
	double blockTime = 0.0;
	double blockLastPressed = 0;
	double leverTime = 0.0;
	double leverLastPressed = 0;
};
