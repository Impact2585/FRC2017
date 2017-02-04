#include "Toggler.h"

/**
 * Constructor that sets the previous button state and value to check to false.
 */
Toggler::Toggler() : prevInput(false), val(false) {

}

Toggler::~Toggler() {

}

/**
 * Checks whether val should be toggled and gets the state of val.
 * Toggles the state of val if the input button has been pressed and the previous button state is unpressed.
 *
 * @param input the input button to query.
 * @return the current state of val.
 */
bool Toggler::checkToggle(bool input) {
	if(input && !prevInput) {
		val ^= true;		
	}

	prevInput = input;
	return val;
}
