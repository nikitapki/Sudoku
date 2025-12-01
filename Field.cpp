#include "Field.hpp"

CoordinateTableSudoku Field::translatorIndexInRowCol(int indexSudokuMassive) {
	CoordinateTableSudoku coordinateCell;
	coordinateCell.position_x = indexSudokuMassive % SIZE_SUDOKU;
	coordinateCell.position_y = indexSudokuMassive / SIZE_SUDOKU;
	return coordinateCell;
}

void Field::InitializeQuantityEmptyValues() {
	memset(quantityValues, 0, sizeof(quantityValues));
}

void Field::InitializeFieldEmptyValues() {
	for (int i = 0; i < SIZE_SUDOKU_N_X_N; i++) {
		field[i].value = 0;
		field[i].is_fixed = true;
	}
}