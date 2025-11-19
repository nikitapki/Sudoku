#include <iostream>
#include "Manager.hpp"
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Manager gener;
	gener.fillGrid();
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		for (int j = 0; j < SIZE_SUDOKU; j++) {
			std::cout << gener.grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}