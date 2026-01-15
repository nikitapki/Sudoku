#include "MenuRenderer.hpp"

CommandsMenu MenuRenderer::drawMenu() {
	handler->ClearConsole();

	std::wstring padW = L"                                          ";

	std::wcout << padW << L"╔══════════════╗" << std::endl;
	std::wcout << padW << L"║    Играть    ║" << std::endl;
	std::wcout << padW << L"╚══════════════╝" << std::endl;
	std::wcout << padW << L"╔══════════════╗" << std::endl;
	std::wcout << padW << L"║    Выход     ║" << std::endl;
	std::wcout << padW << L"╚══════════════╝" << std::endl;

	CommandsMenu result;
	bool exitFromCycl = false;
	do {

		PhysicCoordinateCell consoleCoord = handler->clickToConsole();

		if (consoleCoord.getX() >= MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS &&
			consoleCoord.getX() <= MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS) {
			if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY) {
				result = CommandsMenu::playGame;
				exitFromCycl = true;
			}
			else if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT
				&& consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT) {
				result = CommandsMenu::exitGame;
				exitFromCycl = true;
			}
		}
	} while (!exitFromCycl);

	handler->setCursorOnOldCoordinates();

	return result;
}

int MenuRenderer::drawSettingsDifficulty() {
	handler->ClearConsole();

	std::wstring padW = L"                                          ";

	std::wcout << padW << L"╔═════════════════╗" << std::endl;
	std::wcout << padW << L"║   Легкий        ║" << std::endl;
	std::wcout << padW << L"╚═════════════════╝" << std::endl;
	std::wcout << padW << L"╔═════════════════╗" << std::endl;
	std::wcout << padW << L"║   Средний       ║" << std::endl;
	std::wcout << padW << L"╚═════════════════╝" << std::endl;
	std::wcout << padW << L"╔═════════════════╗" << std::endl;
	std::wcout << padW << L"║   Сложный       ║" << std::endl;
	std::wcout << padW << L"╚═════════════════╝" << std::endl;
	std::wcout << padW << L"╔═════════════════╗" << std::endl;
	std::wcout << padW << L"║   Невозможный   ║" << std::endl;
	std::wcout << padW << L"╚═════════════════╝" << std::endl;
	std::wcout << padW << L"╔═════════════════╗" << std::endl;
	std::wcout << padW << L"║   Вернуться     ║" << std::endl;
	std::wcout << padW << L"╚═════════════════╝" << std::endl;

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