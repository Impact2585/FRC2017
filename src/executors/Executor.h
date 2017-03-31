/*
 * Executor.h
 */

#ifndef SRC_EXECUTORS_EXECUTOR_H_
#define SRC_EXECUTORS_EXECUTOR_H_

#include "../systems/RobotSystem.h"
#include "../Environment.h"
#include <vector>
#include <memory>

class Executor {
public:
    Executor(std::shared_ptr<Environment> environ);
    virtual ~Executor();
    virtual void execute() = 0;
protected:
    std::shared_ptr<Environment> environ;
    std::map<std::string, std::shared_ptr<RobotSystem>>& systems;
};



#endif /* SRC_EXECUTORS_EXECUTOR_H_ */
