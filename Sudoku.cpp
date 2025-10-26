#include <iostream>
#include "Manager.hpp"
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Manager gener;
	gener.generateMassiveNums();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			std::cout << gener.massive_sudoku[i][j] << " ";
		}
		std::cout << std::endl;
	}
}