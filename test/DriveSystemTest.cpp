#include "DriveSystemTest.h"
#include <stdio.h>

DriveSystemTest::DriveSystemTest() {
	input = std::make_shared<TestInputMethod>();
	drive = std::make_unique<DriveSystem>(input);
	TEST_ADD(DriveSystemTest::testInit)
	TEST_ADD(DriveSystemTest::testRamp)
}

DriveSystemTest::~DriveSystemTest() {

}

void DriveSystemTest::testInit() {
	runDrive();
	TEST_ASSERT(currRampForward == 0);
}

void DriveSystemTest::testRamp() {
	static_cast<TestInputMethod*>(input.get())->setDesiredForward(0.5);
	runDrive();
	TEST_ASSERT(currRampForward == round2(0.4));
	runDrive();
	TEST_ASSERT(currRampForward == 0.5);
	
	static_cast<TestInputMethod*>(input.get())->setDesiredForward(0.2);
	runDrive();
	TEST_ASSERT(currRampForward == round2(0.26));
	
	static_cast<TestInputMethod*>(input.get())->setDesiredForward(-0.5);
	runDrive();
	printf("%f\n", currRampForward);
	TEST_ASSERT(round2(currRampForward) == round2(-0.348));
	
	static_cast<TestInputMethod*>(input.get())->setDesiredForward(0);
	runDrive();
	TEST_ASSERT(currRampForward == 0);
	
}

void DriveSystemTest::runDrive() {
	drive->run();
	currRampForward = drive->getCurrentRampForward();
}

float DriveSystemTest::round2(float toRound) {
	return roundf(toRound * 100) / 100;
}
