#pragma once

#include "Renderer.hpp"

class MenuController {
private:
	MouseHandler* handlerClicks;
public:
	Renderer renderMenu;

	MenuController(MouseHandler* handler) : renderMenu(handler) { 
		handlerClicks = handler;
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