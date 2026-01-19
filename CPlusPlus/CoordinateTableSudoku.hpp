#pragma once
class CoordinateTableSudoku {
private:
	int position_x;
	int position_y;
public:
	CoordinateTableSudoku() {
		position_x = 0;
		position_y = 0;
	}

	void setPosition_x(int position_x) {
		this->position_x = position_x;
	}

	void setPosition_y(int position_y) {
		this->position_y = position_y;
	}

	int getPosition_x() {
		return position_x;
	}

	int getPosition_y() {
		return position_y;
	}
};
