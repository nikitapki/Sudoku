#ifndef MANAGER_SUDOKU
#define MANAGER_SUDOKU

#include "RandomLCG.hpp"

// временно
#include <iostream>
#include <iomanip>

#define SIZE_SUDOKU 10

class Manager
{
private:
	RandomLCG rand;

	// Контроллер комбинаций
	// Проверяет можно ли подставить значение по заданным координатам в заданном массиве
	// (значение уже находится в массиве по заданным координатам)
	bool checkerCombinations(int coord_y, int coord_x, int massive_sudoku[][SIZE_SUDOKU]);

public:
	int massive_sudoku[SIZE_SUDOKU][SIZE_SUDOKU] = { 0 };

	void generateMassiveNums();
};

#endif // !MANAGER_SUDOKU