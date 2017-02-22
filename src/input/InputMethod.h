/*
 * InputMethod.h
 */

#ifndef SRC_INPUT_INPUTMETHOD_H_
#define SRC_INPUT_INPUTMETHOD_H_
#include "../XboxConstants.h"

class InputMethod {
public:
	InputMethod();
	virtual ~InputMethod();

	virtual double getForwardDistance() = 0;
	virtual double getSidewaysDistance() = 0;
	virtual bool toggleDrive() = 0;

	virtual bool shootToggle() = 0;
	
	virtual bool intake() = 0;
	virtual bool outtake() = 0;
    
	virtual bool toggleBlockHolder() = 0;
	virtual bool toggleLever() = 0;
};



#endif /* SRC_INPUT_INPUTMETHOD_H_ */
