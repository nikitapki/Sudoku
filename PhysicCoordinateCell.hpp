#pragma once

#include "Config.hpp"

class PhysicCoordinateCell {
private:
	SHORT x;
	SHORT y;

public:
	PhysicCoordinateCell() {
		x = 0;
		y = 0;
	}

	void setX(SHORT x) {
		this->x = x;
	}

	void setY(SHORT y) {
		this->y = y;
	}

	SHORT getX() {
		return x;
	}

	SHORT getY() {
		return y;
	}

	void calculationMinusX(int num) {
		x -= num;
	}

	void calculationMinusY(int num) {
		y -= num;
	}

	void calculationPlusX(int num) {
		x += num;
	}

	void calculationPlusY(int num) {
		y += num;
	}
};