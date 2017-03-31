#ifndef TEST_DRIVESYSTEMTEST_H_
#define TEST_DRIVESYSTEMTEST_H_
#include <cpptest-assert.h>
#include <cpptest-suite.h>
#include <cmath>

#include "../src/systems/DriveSystem.h"
#include "TestInputMethod.h"

class DriveSystemTest : public Test::Suite {
public:
    DriveSystemTest(); 
    ~DriveSystemTest();
    void runDrive();
private:
    void testInit();
    void testRamp();
    float round2(float toRonud);
    std::unique_ptr<DriveSystem> drive;
    std::shared_ptr<InputMethod> input;
    float currRampForward;
    float rotateValue;
};

#endif


