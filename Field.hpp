#ifndef FIELD
#define FIELD

#include "Config.hpp"

typedef struct Cell{
	int value;
	bool is_fixed;
	int position_x;
	int position_y;
} Cell;

class Field
{
private:
	// –азмер пол€ судоку (общий)
	int sizeSudokuNxN = SIZE_SUDOKU * SIZE_SUDOKU;

public:
	// ћассив структур, хран€щий игровое поле
	Cell* field;

	//  ол-во каждого значени€, которое можно ввести в судоку (0 инд - общее кол-во, 1-9 инд соотв с значением)
	int quantityValues[SIZE_SUDOKU + 1] = { 0 };

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