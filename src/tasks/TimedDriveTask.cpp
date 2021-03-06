#include "TimedDriveTask.h"

/**
 * Constructor that sets the system, time to drive, and direction.
 *
 * @param system the drive system.
 * @param timeDriving the time to drive in seconds.
 * @param direction true if forward, false if backwards.
 */
TimedDriveTask::TimedDriveTask(std::shared_ptr<RobotSystem> system, float forwardVal, float rotateVal, double timeDriving) : drive(system), forward(forwardVal), rotate(rotateVal), timeToDrive(timeDriving), timeElapsed(0) {
#ifndef TESTING
    timer = std::make_unique<Timer>();
#else 
    start = std::clock();
#endif
}

TimedDriveTask::~TimedDriveTask() {

}

/**
 * Starts the timer.
 */
void TimedDriveTask::onStart() {
#ifndef TESTING
    timer->Start();
#endif
}

/**
 * Updates time elapsed and drives in the direction specified.
 */
void TimedDriveTask::execute() {
    static_cast<DriveSystem*>(drive.get())->arcadeControl(forward, rotate, false);
#ifndef TESTING
    timeElapsed = timer->Get();
#else
    timeElapsed = (std::clock - start) / (double) CLOCKS_PER_SEC;
#endif
}

/**
 * Stops the drive system.
 */
void TimedDriveTask::onEnd() {
    static_cast<DriveSystem*>(drive.get())->arcadeControl(0, 0, false);
}

/**
 * Checks if the time is elapsed.
 */
bool TimedDriveTask::checkIfFinished() {
    return timeElapsed >= timeToDrive;
}

