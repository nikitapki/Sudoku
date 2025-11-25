#ifndef MANAGER_SUDOKU
#define MANAGER_SUDOKU

#include "RandomLCG.hpp"
#include "Config.hpp"
#include "Field.hpp"

// временно
#include <iostream>
#include <iomanip>

class Manager
{
private:
	RandomLCG rand;

	// Функция проверки комбинации
	// Проверка можно ли поставить указанное значение по указанным координатам
	bool checkerCombinations(int coord_y, int coord_x, int value);

	// Функция поиска пустой клетки в таблице
	bool findEmpty(int* coord_y, int* coord_x);

	// Сама таблица судоку (временное хранилище в дальнейшем переносится в Field)
	int grid[SIZE_SUDOKU][SIZE_SUDOKU];

	// Заполняет таблицу судоку различными значениями. Генерация рандомных комбинаций игры
	bool fillGrid();

	// Удаление ячеек для генерации самой игры
	void removeCells(int quantityRemoves);

public:
	// Хранилище игрового поля
	Field gridCells;

	// Генерация игрового поля
	void generateNewGame(int quantityRemoves);


	// Пока разборка куда это поместить, будет временно здесь

	bool processCellInput(int pos_y, int pos_x, int value);


};

#endif // !MANAGER_SUDOKU