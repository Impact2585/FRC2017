/**
 * Toggler.h
 */

class Toggler {
public:
	Toggler();
	~Toggler();
	bool checkToggle(bool input);
private:
	bool prevInput;
	bool val;
};
