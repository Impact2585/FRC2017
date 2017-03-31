#include "GearboxSystemTest.h"
#include <stdio.h>

/**
 * Constructor that zeroes the gear holder and lever motor speeds and initializes the gear box system and input method.
 */
GearboxSystemTest::GearboxSystemTest() : blockSpeed(0), leverSpeed(0) {
    input = std::make_shared<TestInputMethod>();
    gearbox = std::make_unique<GearboxSystem>(input);
    TEST_ADD(GearboxSystemTest::testStart)
    TEST_ADD(GearboxSystemTest::testInterrupt)
    TEST_ADD(GearboxSystemTest::testFinish)
    TEST_ADD(GearboxSystemTest::testSwitch)
}

GearboxSystemTest::~GearboxSystemTest() {

}

void GearboxSystemTest::setLeverToggle(bool toggle) {
    static_cast<TestInputMethod*>(input.get())->setLeverToggle(toggle);
}

void GearboxSystemTest::setGearHolderToggle(bool toggle) {
    static_cast<TestInputMethod*>(input.get())->setBlockHolderToggle(toggle);
}

void GearboxSystemTest::testStart() {
    setLeverToggle(true);
    runSystem();
    TEST_ASSERT(round(leverSpeed) == round(GearboxSystem::LEVER_SPEED));
    TEST_ASSERT(blockSpeed == 0);

    setGearHolderToggle(true);
    runSystem();
    TEST_ASSERT(leverSpeed == GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == GearboxSystem::BLOCK_SPEED);

    setLeverToggle(false);
    setGearHolderToggle(false);
    runSystem(); 
    TEST_ASSERT(leverSpeed == GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == GearboxSystem::BLOCK_SPEED);

}

void GearboxSystemTest::testFinish() {
    gearbox->getLeverSystem()->currTime = GearboxSystem::LEVER_TIME - 1;
    gearbox->getBlockHolderSystem()->currTime = GearboxSystem::BLOCK_TIME - 1;
    runSystem();
    TEST_ASSERT(leverSpeed == GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == GearboxSystem::BLOCK_SPEED);

    gearbox->getLeverSystem()->currTime = GearboxSystem::LEVER_TIME;
    gearbox->getBlockHolderSystem()->currTime = GearboxSystem::BLOCK_TIME;
    runSystem();
    TEST_ASSERT(leverSpeed == 0);
    TEST_ASSERT(blockSpeed == 0);

}

void GearboxSystemTest::testSwitch() {
    setLeverToggle(true);
    setGearHolderToggle(true);
    runSystem();
    TEST_ASSERT(leverSpeed == -GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == -GearboxSystem::BLOCK_SPEED);

    runSystem();
    TEST_ASSERT(leverSpeed == -GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == -GearboxSystem::BLOCK_SPEED);

}

void GearboxSystemTest::testInterrupt() {
    setLeverToggle(true);
    setGearHolderToggle(true);
    runSystem();
    TEST_ASSERT(leverSpeed == GearboxSystem::LEVER_SPEED);
    TEST_ASSERT(blockSpeed == GearboxSystem::BLOCK_SPEED);

    setLeverToggle(false);
    setGearHolderToggle(false);

}

void GearboxSystemTest::runSystem() {
    gearbox->run();
    leverSpeed = round(-gearbox->getLeverSpeed());
    blockSpeed = round(-gearbox->getBlockSpeed());
}

float GearboxSystemTest::round(float toRound) {
    return roundf(toRound * 10) / 10;
}
