#define TESTING
#include "DriveSystemTest.h"
#include <memory>
#include <cpptest-textoutput.h>

int main(int argc, char **argv) {
	Test::Suite suites;
	suites.add(std::auto_ptr<Test::Suite>(new DriveSystemTest()));
	Test::TextOutput output(Test::TextOutput::Verbose);
	suites.run(output);
	return 0;
}
