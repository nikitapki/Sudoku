#include <iostream>
#include <locale>
#include <windows.h>

#include "Manager.hpp"
#include "Game.hpp"
#include "Renderer.hpp"
#include "MouseHandler.hpp"

int main() {
	setlocale(LC_ALL, ".UTF8");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	Game startGame;

	/*Manager gener;
	gener.fillGrid();
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		for (int j = 0; j < SIZE_SUDOKU; j++) {
			std::cout << gener.grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	gener.removeCells(10);
	for (int i = 0; i < SIZE_SUDOKU; i++) {
		for (int j = 0; j < SIZE_SUDOKU; j++) {
			std::cout << gener.grid[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
}