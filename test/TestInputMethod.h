#ifndef TEST_TESTINPUTMETHOD_H_
#define TEST_TESTINPUTMETHOD_H_

#include "../src/input/InputMethod.h"

class TestInputMethod : public InputMethod {
public:
	TestInputMethod();
	virtual ~TestInputMethod();
	virtual double getForwardDistance();
	virtual double getSidewaysDistance();
	virtual bool toggleDrive();

	virtual bool shoot();
	
	virtual bool intake();
	virtual bool outtake();

	void setDesiredForward(float val);
    void setFinished(bool finished);
    bool isFinished();
private:
	float desiredForwardVal;
    bool finished;
};

#endif
