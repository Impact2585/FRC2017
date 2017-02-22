#ifndef TEST_GEARBOXSYSTEM_H_
#define TEST_GEARBOXSYSTEM_H_
#include <cpptest-assert.h>
#include <cpptest-suite.h>
#include <cmath>

#include "../src/systems/GearboxSystem.h"
#include "TestInputMethod.h"

class GearboxSystemTest : public Test::Suite {
public:
    GearboxSystemTest();
    ~GearboxSystemTest();
private:
    void runSystem();
    void testStart();
    void testInterrupt();
    void testFinish();
    void testSwitch();
    void setLeverToggle(bool toggle);
    void setGearHolderToggle(bool toggle);
    std::unique_ptr<GearboxSystem> gearbox;
    std::shared_ptr<InputMethod> input;
    float blockSpeed;
    float leverSpeed;
    float round(float toRound);
};

#endif
