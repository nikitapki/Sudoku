#include "Field.hpp"

typedef struct {
	int value;
	bool is_fixed;
	bool is_selected = false;
	int position_x;
	int position_y;
} Cell;

Field::Field() {
	field = new Cell[sizeSudokuNxN];
}

void Field::InitializeFullGrid(int massiveCells[][SIZE_SUDOKU]) {
	for (int i = 0; i < sizeSudokuNxN; i++) {
		field[i].value = massiveCells[i / SIZE_SUDOKU][i % SIZE_SUDOKU];
		field[i].is_fixed = true;
		field[i].position_y = i / SIZE_SUDOKU;
		field[i].position_x = i % SIZE_SUDOKU;
		field[i].is_selected = false;
	}
}

void Field::InitializeGameRound(int massiveCells[][SIZE_SUDOKU]) {
	for (int i = 0; i < sizeSudokuNxN; i++) {
		(field[i].value == 0) ? field[i].is_fixed = false : field[i].is_fixed = true;
	}
}