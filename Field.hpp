#pragma once

#include "Config.hpp"

typedef struct Cell{
	int value;
	bool is_fixed;
} Cell;

typedef struct CoordinateTableSudoku {
	int position_x;
	int position_y;
} CoordinateTableSudoku;

class Field {
public:
	// Массив структур, хранящий игровое поле
	std::unique_ptr<Cell[]> field;

	// Кол-во каждого значения, которое можно ввести в судоку (0 инд - общее кол-во, 1-9 инд соотв с значением)
	int quantityValues[SIZE_COUNTER_IMPUT_NUMS];

	// Конструктор поля выделяет сразу память под поле и очищает память за собой и отмечает указате
	Field() {
		field = std::make_unique<Cell[]>(SIZE_SUDOKU_N_X_N);

		InitializeQuantityEmptyValues();
	}

	// Переводчик из одномерных индексных координат в двумерное расположение ячейки
	CoordinateTableSudoku translatorIndexInRowCol(int indexSudokuMassive);

	// Инициализация пустого массива счетчика фиксированных значений (общий и конкретных)
	void InitializeQuantityEmptyValues();

	// Инициализация пустого поля судоку
	void InitializeFieldEmptyValues();
};
