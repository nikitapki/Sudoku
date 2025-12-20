#include "MenuRenderer.hpp"

CommandsMenu MenuRenderer::drawMenu() {
	handler->ClearConsole();

	std::cout << pad << u8"╔══════════════╗" << std::endl;
	std::cout << pad << u8"║    Играть    ║" << std::endl;
	std::cout << pad << u8"╚══════════════╝" << std::endl;
	std::cout << pad << u8"╔══════════════╗" << std::endl;
	std::cout << pad << u8"║    Выход     ║" << std::endl;
	std::cout << pad << u8"╚══════════════╝" << std::endl;

	CommandsMenu result;
	bool exitFromCycl = false;
	do {

		PhysicCoordinateCell consoleCoord = handler->clickToConsole();

		if (consoleCoord.getX() >= MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS &&
			consoleCoord.getX() <= MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS) {
			if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY) {
				result = playGame;
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT) {
				result = exitGame;
				exitFromCycl = true;
			}
		}
	} while (!exitFromCycl);

	handler->setCursorOnOldCoordinates();

	return result;
}

int MenuRenderer::drawSettingsDifficulty() {
	handler->ClearConsole();

	std::cout << pad << u8"╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   Легкий        ║" << std::endl;
	std::cout << pad << u8"╚═════════════════╝" << std::endl;
	std::cout << pad << u8"╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   Средний       ║" << std::endl;
	std::cout << pad << u8"╚═════════════════╝" << std::endl;
	std::cout << pad << u8"╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   Сложный       ║" << std::endl;
	std::cout << pad << u8"╚═════════════════╝" << std::endl;
	std::cout << pad << u8"╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   Невозможный   ║" << std::endl;
	std::cout << pad << u8"╚═════════════════╝" << std::endl;
	std::cout << pad << u8"╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   Вернуться     ║" << std::endl;
	std::cout << pad << u8"╚═════════════════╝" << std::endl;

	int result;
	bool exitFromCycl = false;
	do {
		PhysicCoordinateCell consoleCoord = handler->clickToConsole();

		if (consoleCoord.getX() >= MIN_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS &&
			consoleCoord.getX() <= MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS) {
			if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY) {
				result = randomDifficult.random(18, 27);
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM) {
				result = randomDifficult.random(30, 40);
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD) {
				result = randomDifficult.random(41, 50);
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE) {
				result = randomDifficult.random(51, 60);
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK) {
				result = -1;
				exitFromCycl = true;
			}
		}
	} while (!exitFromCycl);

	handler->setCursorOnOldCoordinates();

	return result;
}