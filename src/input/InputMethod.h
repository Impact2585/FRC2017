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

    virtual bool shiftGears() = 0;

    virtual bool shouldWind() = 0;
    virtual bool shouldUnwind() = 0;

    virtual bool increaseShootSpeed() = 0;
    virtual bool decreaseShootSpeed() = 0;

    virtual void setBlockHolderToggler(bool toggle);

    virtual bool incFeederSpeed() = 0;
    virtual bool decFeederSpeed() = 0;
protected:
    bool toggleBlock;
};



#endif /* SRC_INPUT_INPUTMETHOD_H_ */
