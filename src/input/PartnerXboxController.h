/*
 * PartnerXboxController.h
 */

#ifndef SRC_INPUT_PARTNERXBOXCONTROLLER_H_
#define SRC_INPUT_PARTNERXBOXCONTROLLER_H_

#include <Joystick.h>
#include "InputMethod.h"
#include <memory>

class PartnerXboxController : public InputMethod {
public:
    PartnerXboxController();
    ~PartnerXboxController();
    virtual double getForwardDistance();
    virtual double getSidewaysDistance();
    virtual bool toggleDrive();
    virtual bool shootToggle();
    
    virtual bool intake();
    virtual bool outtake();

    virtual bool toggleBlockHolder();
    virtual bool toggleLever();

    virtual bool shiftGears();

    virtual bool shouldWind();
    virtual bool shouldUnwind();

    virtual bool increaseShootSpeed();
    virtual bool decreaseShootSpeed();
private:
    std::unique_ptr<Joystick> joystick1;
    std::unique_ptr<Joystick> joystick2;
};



#endif /* SRC_INPUT_XBOXCONTROLLER_H_ */
