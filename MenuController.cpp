#include "MenuController.hpp"

int MenuController::controlMenu() {
	int result = -1;
	bool exitCycl = false;
	do {
		if (renderMenu.drawMenu() == playGame) {
			result = renderMenu.drawSettingsDifficulty();
			if (result != -1) {
				exitCycl = true;
			}
		}
		else {
			renderMenu.ClearConsole();
			exit(0);
		}
		renderMenu.ClearConsole();
	} while (!exitCycl);

	return result;
}