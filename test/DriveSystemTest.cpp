#include "DriveSystemTest.h"

/**
 * Constructor that initializes the input method, drivesystem and adds the tests.
 */
DriveSystemTest::DriveSystemTest() {
    input = std::make_shared<TestInputMethod>();
    drive = std::make_unique<DriveSystem>(input);
    TEST_ADD(DriveSystemTest::testInit)
    TEST_ADD(DriveSystemTest::testRamp)
}

DriveSystemTest::~DriveSystemTest() {

}

/**
 * tests if the drive system does not drive forward when starting.
 */
void DriveSystemTest::testInit() {
    runDrive();
    TEST_ASSERT(currRampForward == 0);
}

/** 
 * tests if the drivesystem correctly ramps.
 */
void DriveSystemTest::testRamp() {

    /** Tests ramp. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(0.5);
    runDrive();
    TEST_ASSERT(currRampForward == round2(0.4));

    /** Should finish ramping up to desired ramp forward. */
    runDrive();
    TEST_ASSERT(currRampForward == 0.5);

    /** Tests decreasing ramp. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(0.2);
    runDrive();
    TEST_ASSERT(currRampForward == round2(0.26));

    /** Tests reversing. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(-0.5);
    runDrive();
    TEST_ASSERT(round2(currRampForward) == round2(-0.348));

    /** Tests if the motors are immediately set to 0 if input is set to 0. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(0);
    runDrive();
    TEST_ASSERT(currRampForward == 0);

    /** Tests deadZone. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(DriveSystem::DEADZONE - 0.01);
    runDrive();
    TEST_ASSERT(currRampForward == 0);

    /** Tests opposite deadzone. */
    static_cast<TestInputMethod*>(input.get())->setDesiredForward(-DriveSystem::DEADZONE + 0.01);
    runDrive();
    TEST_ASSERT(currRampForward == 0);
}

/**
 * Runs the drive system and gets the currentRampForward.
 */
void DriveSystemTest::runDrive() {
    drive->run();
    currRampForward = drive->getCurrentRampForward();
}

/**
 * Rounds to the nearest hundredth and truncates the rest.
 */
float DriveSystemTest::round2(float toRound) {
    return roundf(toRound * 100) / 100;
}
