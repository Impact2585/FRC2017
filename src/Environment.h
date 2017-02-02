/*
 * Environment.h
 */

#ifndef SRC_ENVIRONMENT_H_
#define SRC_ENVIRONMENT_H_

#include "systems/RobotSystem.h"
#include "systems/DriveSystem.h"
#include "input/XboxController.h"
#include "input/InputMethod.h"
#include <memory>
#include <vector>

class Environment {
public:
	Environment();
	~Environment();
	std::vector<std::unique_ptr<RobotSystem>>& getSystems();

private:
	std::vector<std::unique_ptr<RobotSystem>> systems;
	std::shared_ptr<InputMethod> input;
};



#endif /* SRC_ENVIRONMENT_H_ */
