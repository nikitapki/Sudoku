#include "Game.hpp"

// : render(field) - инициализация render полем(объектом класса) field
Game::Game() 
	: field(std::make_shared<Manager>()),
	handlerClickes(std::make_shared<MouseHandler>()),
	renderField(field, handlerClickes),
	menu(handlerClickes) {

	// ВРЕМЕННО
	// ----------------------
	renderField.draw(22);

	Screen base(handlerClickes); // При использовании в Screen чисто виртуальной функции абстракции класс становится абстрактым и не может существовать сам по себе

	// 1) Вызов виртуальной через НЕвиртуальную базовую функцию
	renderField.draw(99); 

	// 2) Вызов через указатель базового класса после присваивания
	Screen* p = &base;
	p->draw(19.2);

	// ----------------------

	bool endGame = false;
	do {
		bool endRound = false;
		field->generateNewGame(menu.controlMenu(menu.startProgram));

		//roundStart = Clock::now();      // запомнили момент старта раунда

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
