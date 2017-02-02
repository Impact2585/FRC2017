/*
 * XboxController.h
 */

#ifndef SRC_INPUT_XBOXCONTROLLER_H_
#define SRC_INPUT_XBOXCONTROLLER_H_

#include <Joystick.h>
#include "InputMethod.h"
#include <memory>

class XboxController : public InputMethod {
public:
	XboxController();
	~XboxController();
	virtual double getForwardDistance();
	virtual double getSidewaysDistance();

	virtual bool shoot();
private:
	std::unique_ptr<Joystick> joystick;
};



#endif /* SRC_INPUT_XBOXCONTROLLER_H_ */
