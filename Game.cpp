#include "Game.hpp"

// : render(field) - инициализация render полем(объектом класса) field
Game::Game() : render(field, handlerClickes) {
	bool endGame = false;

	field.generateNewGame(10);
	render.drawElementaryField();
	while (!endGame) {
		render.drawValueCell();
	}
	
}