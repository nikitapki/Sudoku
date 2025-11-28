#pragma once

#include "Renderer.hpp"

class MenuController {
public:
	Renderer renderMenu;

	MenuController(MouseHandler* handler) : renderMenu(handler) { }

	int controlMenu();
};