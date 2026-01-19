#pragma once
class GameCoordinate {
private:
    int tableCoord;
    int sudokuNumbersAvailableToInput;
    bool buttonBack;

public:
    GameCoordinate() {
		initialiseCoordinate();
    }

	void initialiseCoordinate() {
		tableCoord = -1;
		sudokuNumbersAvailableToInput = -1;
		buttonBack = false;
	}

	void setTableCoord(int tableCoord) {
		this->tableCoord = tableCoord;
	}

	void setSudokuNumbersAvailableToInput(int sudokuNumbersAvailableToInput) {
		this->sudokuNumbersAvailableToInput = sudokuNumbersAvailableToInput;
	}

	void setButtonBack(bool buttonBack) {
		this->buttonBack = buttonBack;
	}

	int getTableCoord() {
		return tableCoord;
	}

	int getSudokuNumbersAvailableToInput() {
		return sudokuNumbersAvailableToInput;
	}

	bool getButtonBack() {
		return buttonBack;
	}
};
