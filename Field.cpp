#include "Field.hpp"

Field::Field() {
	field = new Cell[sizeSudokuNxN];
}

void Field::InitializeFullGrid(int massiveCells[][SIZE_SUDOKU]) {
	for (int i = 0; i < sizeSudokuNxN; i++) {
		field[i].value = massiveCells[i / SIZE_SUDOKU][i % SIZE_SUDOKU];
		field[i].is_fixed = true;
		field[i].position_y = i / SIZE_SUDOKU;
		field[i].position_x = i % SIZE_SUDOKU;
	}
}

void Field::InitializeGameRound(int massiveCells[][SIZE_SUDOKU]) {
	for (int i = 0; i < sizeSudokuNxN; i++) {
		(massiveCells[i / SIZE_SUDOKU][i % SIZE_SUDOKU] == 0) 
			? field[i].is_fixed = false 
			: field[i].is_fixed = true;
	}
}