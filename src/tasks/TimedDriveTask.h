#ifndef SRC_TASKS_TIMEDDRIVETASK_H_
#define SRC_TASKS_TIMEDDRIVETASK_H_

#ifndef TESTING
#include <Timer.h>
#endif

#include "Task.h"
#include <map>
#include "../systems/RobotSystem.h"
#include "../systems/DriveSystem.h"

class TimedDriveTask : public Task {
public:
	TimedDriveTask(std::map<std::string, std::shared_ptr<RobotSystem>>& systems, int timeDriving);
	~TimedDriveTask();
	virtual void onStart();
	virtual void execute();
	virtual void onEnd();

protected:
	virtual bool checkIfFinished();

private:
	std::shared_ptr<RobotSystem> drive;
#ifndef TESTING
	std::unique_ptr<frc::Timer> timer;
#endif
	int timeToDrive;
	int timeElapsed;
	
};

#endif
