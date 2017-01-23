/*
 * TeleopExecutor.h
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */

#ifndef SRC_EXECUTORS_TELEOPEXECUTOR_H_
#define SRC_EXECUTORS_TELEOPEXECUTOR_H_
#include "Executor.h"

class TeleopExecutor : public Executor {
public:
	TeleopExecutor(std::shared_ptr<Environment> environ);
	~TeleopExecutor();
	virtual void execute();
};



#endif /* SRC_EXECUTORS_TELEOPEXECUTOR_H_ */
