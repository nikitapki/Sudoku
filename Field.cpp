#include "Field.hpp"

CoordinateTableSudoku Field::translatorIndexInRowCol(int indexSudokuMassive) {
	CoordinateTableSudoku coordinateCell;
	coordinateCell.setPosition_x(indexSudokuMassive % SIZE_SUDOKU);
	coordinateCell.setPosition_y(indexSudokuMassive / SIZE_SUDOKU);
	return coordinateCell;
}

void Field::InitializeQuantityEmptyValues() {
	memset(quantityValues, 0, sizeof(quantityValues));
}

void Field::InitializeFieldEmptyValues() {
	for (int i = 0; i < SIZE_SUDOKU_N_X_N; i++) {
		field[i].setValue(0);
		field[i].setIs_fixed(true);
	}
}

// Временно
// ---------------
Field::Field(const Field& other) {
	*this = other;
}
// ---------------
