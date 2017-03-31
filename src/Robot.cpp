/*
 * Robot.cpp
 */
#include "Robot.h"
#include <SmartDashboard/SmartDashboard.h>
#include <CameraServer.h>
#include <chrono>
#include <thread>
#include <opencv2/core/types.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


Robot::Robot() {
    environ = std::make_shared<Environment>();
    centerGear = std::make_shared<CenterTimedGearDelivery>(environ);
    executor = std::make_unique<AutonExecutor>(environ, centerGear);
}

Robot::~Robot() {

}

void Robot::visionThread() {
    cs::UsbCamera cam = CameraServer::GetInstance()->StartAutomaticCapture();
    cam.SetResolution(640,480);
    cs::CvSink sink = CameraServer::GetInstance()->GetVideo();
    cs::CvSource output = CameraServer::GetInstance()->PutVideo("Aquire", 640, 480);

    cv::Mat mat;

    while(true) {
        if(sink.GrabFrame(mat) == 0) {
            output.NotifyError(sink.GetError());
            continue;
        }
        //process mat here

        output.PutFrame(mat);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

    }
}

void Robot::RobotInit() {
    std::thread vision(visionThread);
    vision.detach();
    autonChoice.AddDefault("CenterTimedDrive", centerGear);
    frc::SmartDashboard::PutData("Auton choices", &autonChoice);
}

void Robot::AutonomousInit() {
    //executor.reset(new AutonExecutor(environ, autonChoice.GetSelected()));
    executor.reset(new AutonExecutor(environ, centerGear));

    /**

      static_cast<DriveSystem*>(environ->getSystems().at(DriveSystem::NAME).get())->drive(1, 0, false);
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      static_cast<DriveSystem*>(environ->getSystems().at(DriveSystem::NAME).get())->drive(-1, 0, false);
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
      static_cast<DriveSystem*>(environ->getSystems().at(DriveSystem::NAME).get())->stopAllMotors();

*/
}

/**
 * Sets the executor to a TeleopExecutor.
 */
void Robot::TeleopInit() {
    executor.reset(new TeleopExecutor(environ));
}

void Robot::DisabledInit() {
    environ->stopAll();
}

void Robot::TeleopPeriodic() {
    executor->execute();
}

void Robot::AutonomousPeriodic() {
    executor->execute();
}

void Robot::DisabledPeriodic() {

}

START_ROBOT_CLASS(Robot)



