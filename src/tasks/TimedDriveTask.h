#ifndef SRC_TASKS_TIMEDDRIVETASK_H_
#define SRC_TASKS_TIMEDDRIVETASK_H_

#ifndef TESTING
#include <Timer.h>
#else
#include <ctime>
#endif

#include "Task.h"
#include <map>
#include "../systems/DriveSystem.h"

class TimedDriveTask : public Task {
public:
	TimedDriveTask(std::shared_ptr<RobotSystem> system, double timeDriving, bool direction);
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
#else
    std::clock_t start;
#endif

	double timeToDrive;
	double timeElapsed;
    double speed;
};

#endif
