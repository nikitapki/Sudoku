#pragma once

#include "Renderer.hpp"

class MenuController {
public:
	Renderer renderMenu;

	MenuController(MouseHandler* handler) : renderMenu(handler) { }

	enum ModesRenderringMenu
	{
		startProgram = 0,
		returnFromStartedGame = 1
	};

	int MenuForStartGame();

	int MenuForReturnFromGame();

	int controlMenu(int mode);
};