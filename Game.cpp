#include "Game.hpp"

// : render(field) - инициализация render полем(объектом класса) field
Game::Game() 
	: field(), 
	handlerClickes(),
	renderField(&field, &handlerClickes),
	menu(&handlerClickes) {

	bool endRound = false, endGame = false;
	do {
		field.generateNewGame(menu.controlMenu(menu.startProgram));

		roundStart = Clock::now();      // запомнили момент старта раунда

		renderField.drawElementaryField();

		while (!endRound) {
			if (renderField.drawValueCell()) {
				if (field.gridCells.quantityValues[0] == SIZE_SUDOKU * SIZE_SUDOKU) {
					endRound = true;
				}
			}
			else {
				field.generateNewGame(menu.controlMenu(menu.returnFromStartedGame));
				renderField.drawElementaryField();
			}
		}
		renderField.ClearConsole();

	} while (!endGame);
}