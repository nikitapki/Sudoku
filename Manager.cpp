#include "Manager.hpp"

// Контроллер комбинаций
// Проверяет можно ли подставить значение по заданным координатам в заданном массиве
// (значение уже находится в массиве по заданным координатам)
bool Manager::checkerCombinations(int coord_y, int coord_x, int massive_sudoku[][SIZE_SUDOKU]) {
	bool result = true;
	// Проверка строки на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (massive_sudoku[coord_y][i] == massive_sudoku[coord_y][coord_x]) {
			result = false;
		}
	}
	// Проверка столбца на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (massive_sudoku[i][coord_x] == massive_sudoku[coord_y][coord_x]) {
			result = false;
		}
	}
	// Проверка квадрата 3на3 на повторы
	int offsetCoord_y = coord_y % 3; // offset - смещение 
	int offsetCoord_x = coord_x % 3;
	for (int i = coord_y - offsetCoord_y; i <= coord_y + offsetCoord_y; i++) {
		for (int j = coord_x - offsetCoord_x; j <= coord_x + offsetCoord_x; j++) {
			if (massive_sudoku[i][j] == massive_sudoku[coord_y][coord_x]) {
				result = false;
			}
		}
	}
	
	return result;
}

void Manager::generateMassiveNums() {
	
}