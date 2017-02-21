#include "TestableTaskChain.h"

TestableTaskChain::TestableTaskChain(std::shared_ptr<TestInputMethod> input) : input(input) {

}

TestableTaskChain::~TestableTaskChain() {

}

void TestableTaskChain::init() {
    addTask(std::make_shared<TestTask>(input, std::make_shared<EndSignal>()));
    addTask(std::make_shared<TestTask>(input, std::make_shared<EndSignal>()));
    currTask = tasks.begin();
}
