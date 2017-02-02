/*
 * InputMethod.h
 */

#ifndef SRC_INPUT_INPUTMETHOD_H_
#define SRC_INPUT_INPUTMETHOD_H_
#include "../RobotMap.h"

class InputMethod {
public:
	InputMethod();
	virtual ~InputMethod();

	virtual double getForwardDistance() = 0;
	virtual double getSidewaysDistance() = 0;

	virtual bool shoot() = 0;
};



#endif /* SRC_INPUT_INPUTMETHOD_H_ */
