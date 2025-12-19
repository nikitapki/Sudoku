#pragma once

#include "Config.hpp"
#include <array>
#include "CoordinateTableSudoku.hpp"
#include "Cell.hpp"

class Field {
public:
	// Массив (контейнер) структур, хранящий игровое поле
	std::array<Cell, SIZE_SUDOKU_N_X_N> field;

	// Кол-во каждого значения, которое можно ввести в судоку (0 инд - общее кол-во, 1-9 инд соотв с значением)
	int quantityValues[SIZE_COUNTER_IMPUT_NUMS];

	// Конструктор поля выделяет сразу память под поле и очищает память за собой и отмечает указате
	Field() {
		InitializeQuantityEmptyValues();
		InitializeFieldEmptyValues();
	}

	// Переводчик из одномерных индексных координат в двумерное расположение ячейки
	CoordinateTableSudoku translatorIndexInRowCol(int indexSudokuMassive);

	// Инициализация пустого массива счетчика фиксированных значений (общий и конкретных)
	void InitializeQuantityEmptyValues();

	// Инициализация пустого поля судоку
	void InitializeFieldEmptyValues();
};
