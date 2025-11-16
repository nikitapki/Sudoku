#include "Manager.hpp"

// Контроллер комбинаций
// Проверяет можно ли подставить заданное значение по заданным координатам в таблицу 
// (значение уже находится в массиве по заданным координатам)
bool Manager::checkerCombinations(int coord_y, int coord_x, int value) {
	// Проверка строки на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[coord_y][i] == value) {
			return false;
		}
	}
	// Проверка столбца на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[i][coord_x] == value) {
			return false;
		}
	}
	// Проверка квадрата 3на3 на повторы
	int offsetCoord_y = coord_y - coord_y % SIZE_SQUARE_SUDOKU; // offset - смещение 
	int offsetCoord_x = coord_x - coord_x % SIZE_SQUARE_SUDOKU;
	for (int i = offsetCoord_y; i <= offsetCoord_y + SIZE_SQUARE_SUDOKU; i++) {
		for (int j = offsetCoord_x; j <= offsetCoord_x + SIZE_SQUARE_SUDOKU; j++) {
			if (grid[i][j] == value) {
				return false;
			}
		}
	}

	return true;
}

// Функция поиска первой пустой клетки (в которой находится 0)
// Координаты клетки, записываются по адресу
// Функция возвращает результат записи. Были ли найдены пустые клетки
bool Manager::findEmpty(int* coord_y, int* coord_x) {
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		for (int j = 0; j < SIZE_SUDOKU; j++) {
			if (grid[i][j] == 0) {
				*coord_y = i;
				*coord_x = j;
				return true;
			}
		}
	}
	return false;
}

bool Manager::fillGrid() {
	int coord_y, coord_x;
	while (findEmpty(&coord_y, &coord_x)) {

	}
}