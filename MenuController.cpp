#include "MenuController.hpp"
enum ModesRenderringMenu
{
	startProgram = 0,
	returnFromStartedGame = 1
};

int MenuController::MenuForStartGame() {
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

int MenuController::MenuForReturnFromGame() {
	int result = -1;
	bool exitCycl = false;
	
	result = renderMenu.drawSettingsDifficulty();
	if (result == -1) {
		result = MenuForStartGame();
	}

	renderMenu.ClearConsole();

	return result;
}

int MenuController::controlMenu(int mode) {
	int result = -1;
	if (mode == startProgram) {
		result = MenuForStartGame();
	}

	else if (mode == returnFromStartedGame) {
		result = MenuForReturnFromGame();
	}

	return result;
}