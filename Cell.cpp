#include "Cell.hpp"

bool Cell::rightInputValue() {
	if (value == input_value) {
		return true;
	}
	else {
		return false;
	}
}

void Cell::SetValue(int newValue) {
	input_value = newValue;	
}