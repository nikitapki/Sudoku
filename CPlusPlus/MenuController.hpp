#pragma once

#include "MenuRenderer.hpp"

class MenuController {
private:
	std::shared_ptr<MouseHandler> handlerClicks;
	MenuRenderer renderMenu;
public:
	MenuController(std::shared_ptr<MouseHandler> handler)
		: handlerClicks(std::move(handler)),
		renderMenu(handlerClicks) {
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
