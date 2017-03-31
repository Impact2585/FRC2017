#ifndef SRC_SYSTEMS_LIFTSYSTEM_H_
#define SRC_SYSTEMS_LIFTSYSTEM_H_
#include "RobotSystem.h"
#include "../RobotMap.h"
#include <memory>
#include <Talon.h>

class LiftSystem : public RobotSystem {
public:
    LiftSystem(std::shared_ptr<InputMethod> input);
    virtual ~LiftSystem();
    virtual void run();
    virtual void stopAllMotors();
    void windLift(float speed);
    const static char *NAME;

    static constexpr float SPEED = 1;

private:
    std::unique_ptr<Talon> lift;
};

#endif
