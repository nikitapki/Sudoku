#ifndef MANAGER_SUDOKU
#define MANAGER_SUDOKU

#include "RandomLCG.hpp"

// временно
#include <iostream>
#include <iomanip>

#define SIZE_SUDOKU 10

class Manager
{
public:
	RandomLCG rand;
	int massive_sudoku[SIZE_SUDOKU][SIZE_SUDOKU] = { 0 };

	void generateMassiveNums();
};

#endif // !MANAGER_SUDOKU