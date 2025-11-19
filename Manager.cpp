#include "Manager.hpp"


//  онтроллер комбинаций
// ѕровер€ет можно ли подставить заданное значение по заданным координатам в таблицу 
// (значение уже находитс€ в массиве по заданным координатам)
bool Manager::checkerCombinations(int coord_y, int coord_x, int value) {
	// ѕроверка строки на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[coord_y][i] == value) {
			return false;
		}
	}
	// ѕроверка столбца на повторы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[i][coord_x] == value) {
			return false;
		}
	}
	// ѕроверка квадрата 3на3 на повторы
	int offsetCoord_y = coord_y - coord_y % SIZE_SQUARE_SUDOKU; // offset - смещение 
	int offsetCoord_x = coord_x - coord_x % SIZE_SQUARE_SUDOKU;
	for (int i = offsetCoord_y; i < offsetCoord_y + SIZE_SQUARE_SUDOKU; i++) {
		for (int j = offsetCoord_x; j < offsetCoord_x + SIZE_SQUARE_SUDOKU; j++) {
			if (grid[i][j] == value) {
				return false;
			}
		}
	}

	return true;
}


// ‘ункци€ поиска первой пустой клетки (в которой находитс€ 0)
//  оординаты клетки, записываютс€ по адресу
// ‘ункци€ возвращает результат записи. Ѕыли ли найдены пустые клетки
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


// –екурсивна€ функци€ генерации таблицы судоку
bool Manager::fillGrid() {
	int coord_y, coord_x;

	// ≈сли нету пустых €чеек возвращает true
	if (!findEmpty(&coord_y, &coord_x)) {
		return true;
	}

	//  андидаты дл€ подстановки в поле судоку
	// ѕри добавлении возможности выбора размера пол€ судоку стоит изменить 
	int *candidates = rand.randomGenerateReverseMassive(1, 9);

	// ѕеремешивание чисел в массиве
	rand.randomReverseMassive(candidates, SIZE_SUDOKU);

	// ÷иклически перебираем всех кандидатов и если во врем€ перебора не было возвращено true,
	// возвращаем false и рекурсией возвращаемс€ к подбору другого кандидата и другой комбинации таблицы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		int val = candidates[i];
	
		// ѕроверка заполнени€ таблицы
		// (подходит ли кандидат, если нет рекурсивно возвращаем false и берем другого кандидата)
		if (checkerCombinations(coord_y, coord_x, val)) {
			grid[coord_y][coord_x] = val;

			// –екурсивное возвращение true в случае полного заполнени€ таблицы
			if (fillGrid()) {
				return true;
			}
			// ≈сли не удалось заполнить таблицу по выбранному кандидату очищаем установленное значение
			grid[coord_y][coord_x] = 0;
		}
	}

	delete[] candidates;
	candidates = NULL;

	return false;
}


