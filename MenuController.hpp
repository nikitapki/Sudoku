#ifndef MENU
#define MENU

#include "Renderer.hpp"

class MenuController {
public:
	Renderer renderMenu;

	MenuController(MouseHandler* handler) : renderMenu(handler) { }

	int controlMenu();
};

#endif // !MENU