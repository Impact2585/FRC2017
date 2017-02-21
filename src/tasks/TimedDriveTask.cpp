#include "TimedDriveTask.h"

TimedDriveTask::TimedDriveTask(std::shared_ptr<RobotSystem> system, double timeDriving, bool direction) : drive(system), timeToDrive(timeDriving), timeElapsed(0) {
#ifndef TESTING
	timer = std::make_unique<Timer>();
#else 
   start = std::clock();
#endif
    speed = direction ? 1 : -1;
}

TimedDriveTask::~TimedDriveTask() {

}

void TimedDriveTask::onStart() {
#ifndef TESTING
	timer->Reset();	
    timer->Start();
#endif
}

void TimedDriveTask::execute() {
	static_cast<DriveSystem*>(drive.get())->arcadeControl(speed, 0, false);
#ifndef TESTING
	timeElapsed = timer->Get();
#else
    timeElapsed = (std::clock - start) / (double) CLOCKS_PER_SEC;
#endif
}

void TimedDriveTask::onEnd() {
	static_cast<DriveSystem*>(drive.get())->arcadeControl(0, 0, false);
}

bool TimedDriveTask::checkIfFinished() {
	return timeElapsed == timeToDrive;
}

