#include "TimedDriveTask.h"

TimedDriveTask::TimedDriveTask(std::map<std::string, std::shared_ptr<RobotSystem>>& systems, int timeDriving) : timeToDrive(timeDriving), timeElapsed(0) {
	drive = systems.at(DriveSystem::NAME);
	//drive = dynamic_cast<std::shared_ptr<DriveSystem>>(systems.at(DriveSystem::NAME));
	//drive = dynamic_cast<DriveSystem*>(&systems.at(DriveSystem::NAME));
	timer = std::make_unique<Timer>();
}

TimedDriveTask::~TimedDriveTask() {

}

void TimedDriveTask::onStart() {
	timer->Reset();	
}

void TimedDriveTask::execute() {
	static_cast<DriveSystem*>(drive.get())->arcadeControl(50, 0, false);
	timeElapsed = timer->Get();
}

void TimedDriveTask::onEnd() {
	static_cast<DriveSystem*>(drive.get())->arcadeControl(0, 0, false);
}

bool TimedDriveTask::checkIfFinished() {
	return timeElapsed == timeToDrive;
}

