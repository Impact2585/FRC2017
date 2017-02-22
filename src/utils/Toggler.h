/**
 * Toggler.h
 */

#ifndef SRC_UTILS_TOGGLER_H_
#define SRC_UTILS_TOGGLER_H_
class Toggler {
public:
	Toggler();
	~Toggler();
	bool checkToggle(bool input);
    bool toggled(bool input);
private:
	bool prevInput;
	bool val;
};

#endif
