#ifndef SRC_COMMANDS_TIMEDDRIVECOMMAND_H_
#define SRC_COMMANDS_TIMEDDRIVECOMMAND_H_

#include <Timer.h>
#include "Command.h"
#include <map>
#include "../systems/RobotSystem.h"
#include "../systems/DriveSystem.h"

class TimedDriveCommand : public Command {
public:
	TimedDriveCommand(std::map<std::string, std::shared_ptr<RobotSystem>>& systems, int timeDriving);
	~TimedDriveCommand();
	virtual void onStart();
	virtual void execute();
	virtual void onEnd();

protected:
	virtual bool checkIfFinished();

private:
	std::shared_ptr<RobotSystem> drive;
	std::unique_ptr<frc::Timer> timer;
	int timeToDrive;
	int timeElapsed;
	
};

#endif
