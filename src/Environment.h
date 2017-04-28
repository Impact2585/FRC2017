/*
 * Environment.h
 */

#ifndef SRC_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_H_

#include "systems/RobotSystem.h"
#include "systems/DriveSystem.h"
#include "systems/IntakeSystem.h"
#include "systems/GearboxSystem.h"
#include "systems/ShooterSystem.h"
#include "systems/LiftSystem.h"
#include "input/PartnerXboxController.h"
#include "input/InputMethod.h"
#include <memory>
#include <map>

class Environment {
public:
    Environment();
    ~Environment();
    std::map<std::string, std::shared_ptr<RobotSystem>>& getSystems();
    void stopAll();

private:
    std::map<std::string, std::shared_ptr<RobotSystem>> systems;
    std::shared_ptr<InputMethod> input;
};



#endif /* SRC_ENVIRONMENT_H_ */
