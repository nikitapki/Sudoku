#pragma once

#include "Renderer.hpp"

class MenuController {
private:
	std::shared_ptr<MouseHandler> handlerClicks;
public:
	Renderer renderMenu;

	MenuController(std::shared_ptr<MouseHandler> handler) : renderMenu(handler) {
		Renderer from_copy = handler;
		renderMenu = from_copy; // копирование для лабораторной номер 5 (в будущем убрать)
	}

	enum ModesRenderringMenu
	{
		startProgram = 0,
		returnFromStartedGame = 1
	};

	int MenuForStartGame();

	int MenuForReturnFromGame();

	int controlMenu(int mode);
};
