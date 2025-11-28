#include "Game.hpp"

// : render(field) - инициализация render полем(объектом класса) field
Game::Game() 
	: field(), 
	handlerClickes(),
	renderField(&field, &handlerClickes),
	menu(&handlerClickes) {

	bool endRound = false, endGame = false;
	do {
		field.generateNewGame(menu.controlMenu());
		renderField.drawElementaryField();

		while (!endRound) {
			renderField.drawValueCell();
			if (field.gridCells.quantityValues[0] == SIZE_SUDOKU * SIZE_SUDOKU) {
				endRound = true;
			}
		}
		renderField.ClearConsole();

	} while (!endGame);
}