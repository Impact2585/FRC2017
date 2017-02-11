/*
 * RobotSystem.h
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */

#ifndef SRC_SYSTEMS_ROBOTSYSTEM_H_
#define SRC_SYSTEMS_ROBOTSYSTEM_H_
#include <memory>
#include "../input/InputMethod.h"

class RobotSystem {
public:
	RobotSystem(std::shared_ptr<InputMethod> input);
	virtual ~RobotSystem();
	virtual void run() = 0;
protected:
	std::shared_ptr<InputMethod> input;
};


#endif /* SRC_SYSTEMS_ROBOTSYSTEM_H_ */
