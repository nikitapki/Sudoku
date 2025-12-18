#pragma once

#include "Config.hpp"
#include <array>

typedef struct Cell{
	int value;
	bool is_fixed;
} Cell;

typedef struct CoordinateTableSudoku {
	int position_x;
	int position_y;
} CoordinateTableSudoku;

// перегрузка оператора ==
inline bool operator==(const CoordinateTableSudoku& a, const CoordinateTableSudoku& b) {
	return a.position_x == b.position_x && a.position_y == b.position_y;
}

// перегрузка оператора !=
inline bool operator!=(const CoordinateTableSudoku& a, const CoordinateTableSudoku& b) {
	return !(a == b);
}

class Field {
public:
	// перегрузка оператора []
	//Cell& operator[](int idx) { return field[idx]; }

	// Массив (контейнер) структур, хранящий игровое поле
	std::array<Cell, SIZE_SUDOKU_N_X_N> field;

	// Кол-во каждого значения, которое можно ввести в судоку (0 инд - общее кол-во, 1-9 инд соотв с значением)
	int quantityValues[SIZE_COUNTER_IMPUT_NUMS];

	// Конструктор поля выделяет сразу память под поле и очищает память за собой и отмечает указате
	Field() {
		InitializeQuantityEmptyValues();
		InitializeFieldEmptyValues();
	}

	// Конструктор копирования ПРИМЕР (УБРАТЬ)
	Field(const Field& other) {
		*this = other; 
	}

	// Переводчик из одномерных индексных координат в двумерное расположение ячейки
	CoordinateTableSudoku translatorIndexInRowCol(int indexSudokuMassive);

	// Инициализация пустого массива счетчика фиксированных значений (общий и конкретных)
	void InitializeQuantityEmptyValues();

	// Инициализация пустого поля судоку
	void InitializeFieldEmptyValues();
};
