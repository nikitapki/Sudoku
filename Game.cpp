#include "Game.hpp"

Game::Game() 
	: field(std::make_shared<Manager>()),
	handlerClickes(std::make_shared<MouseHandler>()),
	renderField(field, handlerClickes),
	menu(handlerClickes) {

	bool endGame = false;
	do {
		bool endRound = false;
		field->generateNewGame(menu.controlMenu(menu.startProgram));

		renderField.drawElementaryField();

		while (!endRound) {
			if (renderField.drawValueCell()) {
				if (filledCount(*field) == SIZE_SUDOKU * SIZE_SUDOKU) {
					endRound = true;
				}
			}
			else {
				field->generateNewGame(menu.controlMenu(menu.returnFromStartedGame));
				renderField.drawElementaryField();
			}
		}
		handlerClickes->ClearConsole();

	} while (!endGame);
}
