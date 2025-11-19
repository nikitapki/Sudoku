#ifndef MANAGER_SUDOKU
#define MANAGER_SUDOKU

#include "RandomLCG.hpp"

// временно
#include <iostream>
#include <iomanip>

#define SIZE_SUDOKU 9
#define SIZE_SQUARE_SUDOKU 3

class Manager
{
private:
	RandomLCG rand;

	// Функция проверки комбинеации
	// Проверка можно ли поставить укзанное значение по указанным координатам
	bool checkerCombinations(int coord_y, int coord_x, int value);

	// Функция поиска пустой клетки в таблице
	bool findEmpty(int* coord_y, int* coord_x);

public:
	// Сама таблица судоку
	int grid[SIZE_SUDOKU][SIZE_SUDOKU] = { 0 };

	// Заполняет таблицу судоку различными значениями. Генерация рандомных комбинаций игры
	bool fillGrid();
};

#endif // !MANAGER_SUDOKU