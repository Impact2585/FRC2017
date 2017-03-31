#include "GearboxSystem.h"

#ifdef TESTING
#include "../../test/TestInputMethod.h"
#endif

const char *GearboxSystem::NAME = "GEARBOXSYSTEM";

/**
 * Constructor for the subsystem that controls the gear holder.
 *
 * @param input the input method to set.
 */
GearboxSystem::GearboxSystem(std::shared_ptr<InputMethod> input) : RobotSystem(input), stop(false) {

    blockToggler = std::make_unique<Toggler>();
    leverToggler = std::make_unique<Toggler>();

#ifndef TESTING
    lever = std::make_unique<Spark>(RobotMap::LEVER);
    block = std::make_unique<Spark>(RobotMap::BLOCK_HOLDER);
    limitSwitch = std::make_unique<DigitalInput>(RobotMap::GEAR_LEVER_LIMIT_SWITCH);

#endif

    leverSystem = new struct timedMoveSystem(LEVER_TIME);
    blockSystem = new struct timedMoveSystem(BLOCK_TIME);
}

/**
 * Destructor that deletes the two systems.
 */
GearboxSystem::~GearboxSystem() {
    delete leverSystem;
    delete blockSystem;
}

/**
 * Changes speed's sign based on invert.
 *
 * @param speed the speed on which this changes the sign.
 * @param invert true if negative false if positive.
 * @return the speed with a new sign.
 */
double GearboxSystem::getSpeedFromInversion(double speed, bool invert) {
    return invert ? -speed : speed;
}

/** 
 * Gets the lever system.
 *
 * @return a timedMoveSystem.
 */
struct timedMoveSystem *GearboxSystem::getLeverSystem() {
    return leverSystem;
}

/**
 * Gets the Gear holder system.
 *
 * @return a timedMoveSystem.
 */
struct timedMoveSystem *GearboxSystem::getBlockHolderSystem() {
    return blockSystem;
}

std::shared_ptr<InputMethod> GearboxSystem::getInput() {
    return input;
}

/**
 * function that is continuously called by the teleopexecutor.
 */
void GearboxSystem::run() {
#ifndef TESTING
    stop = limitSwitch->Get();
#else
    stop = static_cast<TestInputMethod*>(input.get())->getLimitSwitchStatus();
#endif
    /** Gets the toggle input from input. */
    bool blockToggle = input->toggleBlockHolder();
    bool leverToggle = input->toggleLever();

    /** Do not toggle if either system is currently moving. */
    if (!leverSystem->moving) {
        leverSystem->checkToggle(leverToggler->toggled(leverToggle));
    }

    if (!blockSystem->moving) {
        blockSystem->checkToggle(blockToggler->toggled(blockToggle));
    }


    //spins motor if it should move and inverts based on toggle direction.
    if (leverSystem->shouldMove() && !(leverSystem->direction && !stop)) {
        spinLeverMotor(getSpeedFromInversion(LEVER_SPEED, leverSystem->direction));
    } else {
        //reset the timer and stop the motor.
        leverSystem->reset();
        spinLeverMotor(0);
    }

    if (blockSystem->shouldMove()) {
        spinBlockMotor(getSpeedFromInversion(BLOCK_SPEED, blockSystem->direction));
    } else {
        blockSystem->reset();
        spinBlockMotor(0);
    }

}


/**
 * Sets the gear holder motor to speed.
 *
 * @param speed the speed to set.
 */
void GearboxSystem::spinBlockMotor(float speed) {
#ifndef TESTING
    block->Set(speed);
#else
    blockSpeed = speed;
#endif
}

/**
 * Sets the lever motor to speed.
 * 
 * @param speed the speed to set.
 */
void GearboxSystem::spinLeverMotor(float speed) {
#ifndef TESTING
    lever->Set(speed);
#else
    leverSpeed = speed;
#endif
}

/**
 * Stops the gear holder motor and the lever motor.
 */
void GearboxSystem::stopAllMotors() {
#ifndef TESTING
    block->Set(0);
    lever->Set(0);
#endif
    blockSpeed = 0;
    leverSpeed = 0;
    leverSystem->moving = false;
    blockSystem->moving = false;
}

/**
 * Gets the current gear holder motor speed. Only used during unit testing.
 *
 * @return the current gear holder motor speed.
 */
float GearboxSystem::getBlockSpeed() {
    return blockSpeed;
}

/**
 * Gets the current lever motor speed. Only used during unit testing.
 *
 * @return the current lever motor speed.
 */
float GearboxSystem::getLeverSpeed() {
    return leverSpeed;
}
