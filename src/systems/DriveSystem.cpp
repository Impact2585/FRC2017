/*
 * DriveSystem.cpp
 */

#include "DriveSystem.h"

/** Name of the system used for reference, */
const char *DriveSystem::NAME = "DRIVESYSTEM";

/**
 * Constructor for the DriveSystem that initializes the RobotDrive and InputMethod.
 *
 * @param input the pointer to the InputMethod to use.
 */
DriveSystem::DriveSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input), currentRampForward(0), prevGearState(false) {
#ifndef TESTING
    leftDrive = new Victor(RobotMap::LEFT_DRIVE);
    leftDrive->SetInverted(true);
    drivetrain = std::make_unique<RobotDrive>(leftDrive, new Victor(RobotMap::RIGHT_DRIVE));
    ballShifter = std::make_unique<Solenoid>(RobotMap::BALL_SHIFTER_PORT);
#endif
    invertDriveToggler = std::make_unique<Toggler>();
    gearShiftToggler = std::make_unique<Toggler>();
}

DriveSystem::~DriveSystem() {

}

/**
 * Wrapper method for calling ArcadeDrive on the actual RobotDrive object for unit testing purposes.
 * 
 * @param forward the value for the forward power of the motors.
 * @param rotation the rotation value for motor power.
 * @param squared whether this should square rotation.
 */
void DriveSystem::drive(double forward, double rotation, bool squared) {
#ifndef TESTING
    drivetrain->ArcadeDrive(forward, rotation, squared);
#endif
}

/**
 * Allows one to control the drivetrain with forward input and sideways input.
 * Ramps the speed of the motors towards the desired input with a ramp constant, so that the motors do not draw too much current.
 *
 * @param desiredForwardValue the speed that the drivetrain should ramp towards when driving forward.
 * @param rotateValue the value that which the drivetrain should move sideways.
 * @param squared whether this should square the rotation value.
 */
void DriveSystem::arcadeControl(double desiredForwardValue, double rotateValue, bool squared) {
    if(desiredForwardValue != 0) {
        double change = desiredForwardValue - currentRampForward;
        //increments by ramp multiplier or sets it to the desiredRampForward if they are too close
        currentRampForward = absval(change) > MIN_INCREMENT ? currentRampForward + change * RAMP : desiredForwardValue;
    } else {
        currentRampForward = 0;
    }
    drive(currentRampForward, rotateValue, squared);
}

/**
 * Sets val to 0 if the absolute value of it is below 0.
 *
 * @param val the reference of the value to set.
 */
void DriveSystem::modifyIfInDeadzone(double& val) {
    val = absval(val) <= DEADZONE ? 0 : val;
}

void DriveSystem::shiftGears(bool on) {
#ifndef TESTING
    ballShifter->Set(on);
#endif
}
/**
 * Called by the TeleopExecutor.
 * Gets input from the inputmethod and drives based on that input.
 */
void DriveSystem::run() {
    /** Gets all the input values. */
    double desiredForwardValue = input->getForwardDistance();
    double desiredRotateValue = input->getSidewaysDistance();
    bool shouldInvert = input->toggleDrive();
    bool shouldShiftGear = input->shiftGears();

    bool gear = gearShiftToggler->checkToggle(shouldShiftGear);

    if(gear != prevGearState) {
        shiftGears(gear);
    }

    /** Inverts if the button is pressed. */
    if(invertDriveToggler->checkToggle(shouldInvert))
        desiredForwardValue *= -1;


    modifyIfInDeadzone(desiredForwardValue);
    modifyIfInDeadzone(desiredRotateValue);

    /** Squares rotation. */
    arcadeControl(desiredForwardValue, desiredRotateValue, true);

    prevGearState = gear;
}

/**
 * Gets the current ramp forward.
 *
 * @return the current ramp forward.
 */
double DriveSystem::getCurrentRampForward() {
    return currentRampForward;
}
/**
 * Stops the drivetrain.
 */
void DriveSystem::stopAllMotors() {
    drive(0, 0, false);
}
