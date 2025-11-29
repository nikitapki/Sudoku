#include "Manager.hpp"

// Проверка строки на повторы
bool Manager::checkerCombinationsFromRow(int coord_y, int value) {
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[coord_y][i] == value) {
			return false;
		}
	}
	return true;
}

// Проверка столбца на повторы
bool Manager::checkerCombinationsFromColumn(int coord_x, int value) {
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		if (grid[i][coord_x] == value) {
			return false;
		}
	}
	return true;
}
 
// Проверка квадрата 3на3 на повторы
bool Manager::checkerCombinationsFromBox(int coord_y, int coord_x, int value) {
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

// Контроллер комбинаций
// Проверяет можно ли подставить заданное значение по заданным координатам в таблицу 
// (значение уже находится в массиве по заданным координатам)
bool Manager::checkerCombinations(int coord_y, int coord_x, int value) {
	return (checkerCombinationsFromRow(coord_y, value)) &&
		(checkerCombinationsFromRow(coord_y, value)) &&
		(checkerCombinationsFromRow(coord_y, value));
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


// Рекурсивная функция генерации таблицы судоку
bool Manager::fillGrid() {
	int coord_y, coord_x;

	// Если нету пустых ячеек возвращает true
	if (!findEmpty(&coord_y, &coord_x)) {
		return true;
	}

	// Кандидаты для подстановки в поле судоку
	// При добавлении возможности выбора размера поля судоку стоит изменить 
	int *candidates = rand.randomGenerateReverseMassive(1, 9);

	// Перемешивание чисел в массиве
	rand.randomReverseMassive(candidates, SIZE_SUDOKU);

	// Циклически перебираем всех кандидатов и если во время перебора не было возвращено true,
	// возвращаем false и рекурсией возвращаемся к подбору другого кандидата и другой комбинации таблицы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		int val = candidates[i];
	
		// Проверка заполнения таблицы
		// (подходит ли кандидат, если нет рекурсивно возвращаем false и берем другого кандидата)
		if (checkerCombinations(coord_y, coord_x, val)) {
			grid[coord_y][coord_x] = val;

			// Рекурсивное возвращение true в случае полного заполнения таблицы
			if (fillGrid()) {
				return true;
			}
			// Если не удалось заполнить таблицу по выбранному кандидату очищаем установленное значение
			grid[coord_y][coord_x] = 0;
		}
	}

	delete[] candidates;
	candidates = NULL;

	return false;
}


// Функция удаления ячеек по заданному количеству (служит как определение сложности судоку)
// Реализовано посредствам девятеричной системы счисления и массива индексов
void Manager::removeCells(int quantityRemoves) {
	int* massiveIndexesGrid = rand.randomGenerateReverseMassive(1, 81);
	for (int i = 0; i < quantityRemoves; i++) {
		grid[(massiveIndexesGrid[i] - 1) / SIZE_SUDOKU][(massiveIndexesGrid[i] - 1) % SIZE_SUDOKU] = 0;
	}
}

void Manager::InitializeCounterFixedCells() {
	for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {
		if (gridCells.field[i].is_fixed) {
			(gridCells.quantityValues[0])++;
			(gridCells.quantityValues[gridCells.field[i].value])++;
		}
	}
}

void Manager::counterFixedCells(int valueCell) {
	gridCells.quantityValues[0] += 1;
	gridCells.quantityValues[gridCells.field[valueCell].value] += 1;
}


// Генерация игрового поля
void Manager::generateNewGame(int quantityRemoves) {

	// Заполнение нулями таблицы
	for (int i = 0; i < SIZE_SUDOKU; ++i) {
		memset(grid[i], 0, sizeof(grid[i]));
	}

	// Заполняем поле псевдослучайной вариацией игры
	fillGrid();

	// Инициализирую объект класса Поле полностью заполненной корректной таблицей
	gridCells.InitializeFullGrid(grid);

	// Удаляем ячейки для подготовки игрового поля
	removeCells(quantityRemoves);

	// Дополняем объект класса Поле пустыми клетка, чтобы указать фиксированные и свободные ячейки
	gridCells.InitializeGameRound(grid);

	// Указываем количество зафиксированных(открытых пользователю) клеток
	InitializeCounterFixedCells();
}

// Проверка на введенное значение, если равны, то устанавливаем ячейку как фиксированную,
// чтобы можно было отобразить значение
bool Manager::checkInputValueInCell(int coordinateCell, int inputValue) {
	bool result = true;

	(gridCells.field[coordinateCell].is_fixed || gridCells.field[coordinateCell].value != inputValue) 
		? result = false 
		: gridCells.field[coordinateCell].is_fixed = true;
	
	return result;
}
