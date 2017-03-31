#include "GearboxSystemTest.h"
#include "DriveSystemTest.h"
#include "tasktests/TaskChainTest.h"
#include <memory>
#include <cpptest-textoutput.h>

int main(int argc, char **argv) {
    Test::Suite suites;
    suites.add(std::auto_ptr<Test::Suite>(new DriveSystemTest()));
    suites.add(std::auto_ptr<Test::Suite>(new TaskChainTest()));
    suites.add(std::auto_ptr<Test::Suite>(new GearboxSystemTest()));
    Test::TextOutput output(Test::TextOutput::Verbose);
    suites.run(output);
    return 0;
}
