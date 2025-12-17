#include "Manager.hpp"

// Проверка строки на повторы
bool Manager::checkerCombinationsFromRow(int coord_y, int value) {
	int idx;
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		idx = coord_y * SIZE_SUDOKU + i;
		if (gridCells.field[idx].value == value) {
			return false;
		}
	}
	return true;
}

// Проверка квадрата 3на3 на повторы
bool Manager::checkerCombinationsFromBox(CoordinateTableSudoku coord, int value) {
	int coord_y = coord.position_y;
	int coord_x = coord.position_x;

	int offsetCoord_y = coord_y - coord_y % SIZE_SQUARE_SUDOKU; // offset - смещение 
	int offsetCoord_x = coord_x - coord_x % SIZE_SQUARE_SUDOKU;

	int idx;

	for (int i = offsetCoord_y; i < offsetCoord_y + SIZE_SQUARE_SUDOKU; i++) {
		for (int j = offsetCoord_x; j < offsetCoord_x + SIZE_SQUARE_SUDOKU; j++) {
			idx = i * SIZE_SUDOKU + j;
			if (gridCells.field[idx].value == value) {
				return false;
			}
		}
	}
	return true;
}

// Проверка столбца на повторы
bool Manager::checkerCombinationsFromColumn(int coord_x, int value) {
	int idx;
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		idx = i * SIZE_SUDOKU + coord_x;
		if (gridCells.field[idx].value == value) {
			return false;
		}
	}
	return true;
}

// Контроллер комбинаций
// Проверяет можно ли подставить заданное значение по заданным координатам в таблицу 
// (значение уже находится в массиве по заданным координатам)
bool Manager::checkerCombinations(int indexCoordinateTableSudoku, int value) {
	CoordinateTableSudoku coord = gridCells.translatorIndexInRowCol(indexCoordinateTableSudoku);
	return 
		(checkerCombinationsFromRow(coord.position_y, value)) &&
		(checkerCombinationsFromColumn(coord.position_x, value)) &&
		(checkerCombinationsFromBox(coord, value));
}


// Функция поиска первой пустой клетки (в которой находится 0)
// Координаты клетки, записываются по адресу
// Функция возвращает результат записи. Были ли найдены пустые клетки
bool Manager::findEmpty(int& indexCoordinateTableSudoku) {
	for (int i = 0; i < SIZE_SUDOKU_N_X_N; i++) {
		if (gridCells.field[i].value == 0) {
			indexCoordinateTableSudoku = i;
			return true;
		}
	}
	return false;
}


// Рекурсивная функция генерации таблицы судоку
bool Manager::fillGrid() {
	int indexCoordinateTableSudoku;

	// Если нету пустых ячеек возвращает true
	if (!findEmpty(indexCoordinateTableSudoku)) {
		return true;
	}

	// Кандидаты для подстановки в поле судоку
	// При добавлении возможности выбора размера поля судоку стоит изменить 
	std::unique_ptr<int[]> candidates = rand.randomGenerateReverseMassive(1, 9);

	// Перемешивание чисел в массиве
	rand.randomReverseMassive(candidates.get(), SIZE_SUDOKU);

	// Циклически перебираем всех кандидатов и если во время перебора не было возвращено true,
	// возвращаем false и рекурсией возвращаемся к подбору другого кандидата и другой комбинации таблицы
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		int val = candidates[i];
	
		// Проверка заполнения таблицы
		// (подходит ли кандидат, если нет рекурсивно возвращаем false и берем другого кандидата)
		if (checkerCombinations(indexCoordinateTableSudoku, val)) {
			gridCells.field[indexCoordinateTableSudoku].value = val;

			// Рекурсивное возвращение true в случае полного заполнения таблицы
			if (fillGrid()) {
				return true;
			}
			// Если не удалось заполнить таблицу по выбранному кандидату очищаем установленное значение
			gridCells.field[indexCoordinateTableSudoku].value = 0;
		}
		
	}

	return false;
}


// Функция снятия фиксации с ячейки (служит как определение сложности судоку)
// Реализовано посредствам девятеричной системы счисления и массива индексов
void Manager::unFixedCell(int quantityRemoves) {
	std::unique_ptr<int[]> massiveIndexesGrid{ rand.randomGenerateReverseMassive(1, 81) };
	for (int i = 0; i < quantityRemoves; i++) {
		gridCells.field[massiveIndexesGrid[i]].is_fixed = false;
	}
}

// Функция подсчета фиксированных ячеек 
void Manager::fillCounterFixedCells() {
	for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {
		if (gridCells.field[i].is_fixed) {
			(gridCells.quantityValues[0])++;
			(gridCells.quantityValues[gridCells.field[i].value])++;
		}
	}
}

// Функция для увеления показателя в массиве счетчика для указанного значения
void Manager::counterFixedCells(int valueCell) {
	(gridCells.quantityValues[0])++;
	(gridCells.quantityValues[valueCell])++;
}


// Генерация игрового поля
void Manager::generateNewGame(int quantityRemoves) {

	// инициализируем пустыми значениями поле
	gridCells.InitializeFieldEmptyValues();

	// инициализируем пустыми значениями счетчик
	gridCells.InitializeQuantityEmptyValues();

	// Заполняем поле псевдослучайной вариацией игры
	fillGrid();

	// Удаляем ячейки для подготовки игрового поля
	// Следовательно убираем с них фиксацию
	unFixedCell(quantityRemoves);

	// Указываем количество зафиксированных(открытых пользователю) клеток
	fillCounterFixedCells();
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

// Функция проверки соответствия чисел на поле. Подходит ли введенное с скрытым
bool Manager::checkerMatchingNums(int inputValue, int indexTableValue) {
	return (gridCells.field[indexTableValue].value == inputValue);
}

// Функция сравнение чисел и возврат булевого значения равны они или нет
bool Manager::compareNums(int num1, int num2) {
	return (num1 == num2);
}

Cell& cell(Manager& m, int idx) {
	return m.gridCells.field[idx];
}

int filledCount(const Manager& m) {
	return m.gridCells.quantityValues[0];
}
