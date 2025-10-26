#include "Cell.hpp"

Cell::Cell(int pos_x, int pos_y) {
	value = 0;
	is_fixed = false;
	is_selected = false;
	position_x = pos_x;
	position_y = pos_y;
}

bool Cell::rightInputValue() {
	if (value == input_value) {
		return true;
	}
	else {
		return false;
	}
}

void Cell::SetValueCreate(int create_value) {
	value = create_value;
}