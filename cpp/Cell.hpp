#pragma once

class Cell{
private:
	int value;
	bool is_fixed;

public:
	Cell() {
		value = 0;
		is_fixed = true;
	}

	void setValue(int value) {
		this->value = value;
	}

	void setIs_fixed(bool is_fixed) {
		this->is_fixed = is_fixed;
	}

	int getValue() {
		return value;
	}

	bool getIs_fixed() {
		return is_fixed;
	}
};
