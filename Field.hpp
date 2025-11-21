#ifndef FIELD
#define FIELD

#include "Config.hpp"

class Field
{
private:
	// –азмер пол€ судоку (общий)
	int sizeSudokuNxN = SIZE_SUDOKU * SIZE_SUDOKU;

public:
	// ћассив структур, хран€щий игровое поле
	Cell* field;

	//  онструктор пол€ выдел€ет сразу пам€ть под поле
	Field();

	// »нициализаци€ заполненного пол€ фиксированными значени€ми
	void InitializeFullGrid(int massiveCells[][SIZE_SUDOKU]);

	// ”становка не фиксированных значений пол€ (с которыми может взаимодействовать пользователь)
	void InitializeGameRound(int massiveCells[][SIZE_SUDOKU]);

	// ƒеструктор очищает выделенную пам€ть
	~Field() {
		delete[] field;
	}
};

#endif // !FIELD