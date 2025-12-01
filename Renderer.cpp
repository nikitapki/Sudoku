#include "Renderer.hpp"

void Renderer::correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord) {
	int x = consoleCoord->x;

	if (consoleCoord->x % 2 == 0) {}
	else if (consoleCoord->x % 4 == 3) {
		(consoleCoord->x)--;
	}
	else if (consoleCoord->x % 4 == 1) {
		(consoleCoord->x)--;
	}
}

void Renderer::translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord) {
	PhysicCoordinateCell local = *consoleCoord;
	local.x -= BASE_OFFSET_X;
	local.y -= BASE_OFFSET_Y; 

	if (consoleCoord->y >= MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
		consoleCoord->y <= MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {

		if (consoleCoord->x >= MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
			consoleCoord->x <= MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {
			coordinate.buttonBack = true;
		}
	}

	if (local.y % 2 != 0 && consoleCoord->y <= MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU &&
		consoleCoord->y >= MIN_Y_FROM_CONSOLE_TABLES_SUDOKU) {
		
		if (local.x % 4 != 0 && consoleCoord->x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord->x >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.tableCoord = local.y / 2 * SIZE_SUDOKU + local.x / 4;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}

	if (consoleCoord->y == Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU) {

		if (local.x % 4 != 0 && consoleCoord->x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord->x >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.sudokuNumbersAvailableToInput = local.x / 4 + 1;
			(coordinate.tableCoord)--;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}
}

// Отрисовка изначальной игры 
// 
// версия оформления
// 
// ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣             ╔═══╦═══╦═══╗\n\
// ║   ║   ║   ║   ║   ║   ║   ║   ║   ║             ║ 1 ║ 2 ║ 3 ║\n\
// ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣             ╠═══╬═══╬═══╣\n\
// ║   ║   ║   ║   ║   ║   ║   ║   ║   ║             ║ 4 ║ 5 ║ 6 ║\n\
// ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣             ╠═══╬═══╬═══╣\n\
// ║   ║   ║   ║   ║   ║   ║   ║   ║   ║             ║ 7 ║ 8 ║ 9 ║\n\
// ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝             ╚═══╩═══╩═══╝\n";
// 
// 
// БУДУЩАЯ ВЕРСИЯ \
std::cout << u8"\
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗     ╔═════════════════╗\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ║   Вернуться     ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ╚═════════════════╝\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ╔═════════════════╗\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ║   Статистика    ║\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ╠═════════════════╣\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ║   Время игры:   ║\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ║    00:00:00     ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ╠═════════════════╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ║     Ошибки:     ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ║        0        ║\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ╚═════════════════╝\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";
// 
// 
// 
// Перед вызовом нужно задать значения в таблицу
void Renderer::drawElementaryField() {

	InitializeCoordinate();
	
	handlerClickes->ClearConsole();

	std::cout << pad << u8"╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗     ╔═════════════════╗" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ║   Вернуться     ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ╚═════════════════╝" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣" << std::endl;
	std::cout << pad << u8"║   ║   ║   ║   ║   ║   ║   ║   ║   ║" << std::endl;
	std::cout << pad << u8"╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << std::endl;

	std::cout << pad << u8"╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗" << std::endl;
	std::cout << pad << u8"║ 1 ║ 2 ║ 3 ║ 4 ║ 5 ║ 6 ║ 7 ║ 8 ║ 9 ║" << std::endl;
	std::cout << pad << u8"╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝" << std::endl;

	int coordCell;
	PhysicCoordinateCell consoleCoord;
	for (int i = 1; i < SIZE_SUDOKU * 2; i += 2) {
		for (int j = 3; j < SIZE_SUDOKU * 4; j += 4) {
			consoleCoord.y = i + BASE_OFFSET_Y;
			consoleCoord.x = j + BASE_OFFSET_X;
			handlerClickes->setCursorOnCoordinates(consoleCoord);
			
			coordCell = ((i - 1) / 2) * SIZE_SUDOKU + ((j - 3) / 4);

			if (field->gridCells.field[coordCell].is_fixed) {
				std::cout << "\b" << field->gridCells.field[coordCell].value;
			}
		}
	}
	handlerClickes->setCursorOnOldCoordinates();
}

bool Renderer::drawValueCell() {

	PhysicCoordinateCell consoleCoord = handlerClickes->clickToConsole();

	translatorСonsoleToTableCoords(&consoleCoord);

	if (coordinate.buttonBack) {
		coordinate.buttonBack = false; // чтобы при повторном заходе не выходило сразу
		return false;
	}

	if (coordinate.tableCoord != pastValueCell) {
		if (field->checkInputValueInCell(coordinate.tableCoord, coordinate.sudokuNumbersAvailableToInput)) {
			handlerClickes->setCursorOnCoordinates(consoleCoord);

			handlerClickes->setColorOnConsole(BACKGROUND_INTENSITY);

			pastValueCell = coordinate.tableCoord;
			field->counterFixedCells(field->gridCells.field[coordinate.tableCoord].value);

			handlerClickes->setStandartedColorOnConsole();
		}

		PhysicCoordinateCell coordinatesNotPermanent; // не постоянные координаты
		for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {

			coordinatesNotPermanent = translatorTableToConsoleCoords(i);;

			handlerClickes->setCursorOnCoordinates(coordinatesNotPermanent);

			if (coordinate.sudokuNumbersAvailableToInput == field->gridCells.field[i].value && 
				field->gridCells.field[i].is_fixed) {
				handlerClickes->setColorOnConsole(BACKGROUND_INTENSITY);

				std::cout << "\b\b" << " " << field->gridCells.field[i].value << " ";

				handlerClickes->setStandartedColorOnConsole();
			}
			else {
				if (pastValueTableNumbers == field->gridCells.field[i].value && field->gridCells.field[i].is_fixed) {
					std::cout << "\b\b" << " " << field->gridCells.field[i].value << " ";
				}
			}
		}
		pastValueTableNumbers = coordinate.sudokuNumbersAvailableToInput;
	}

	handlerClickes->setCursorOnOldCoordinates();

	return true;
}

PhysicCoordinateCell Renderer::translatorTableToConsoleCoords(int coordinateCell) {
	PhysicCoordinateCell coord{ 0 };
	coord.y = coordinateCell / SIZE_SUDOKU * 2 + 1 + BASE_OFFSET_Y;
	coord.x = coordinateCell % SIZE_SUDOKU * 4 + 3 + BASE_OFFSET_X;

	return coord;
}

CommandsMenu Renderer::drawMenu() {
	handlerClickes->ClearConsole();

	std::cout << pad << u8"╔══════════════╗" << std::endl;
	std::cout << pad << u8"║    Играть    ║" << std::endl;
	std::cout << pad << u8"╚══════════════╝" << std::endl;
	std::cout << pad << u8"╔══════════════╗" << std::endl;
	std::cout << pad << u8"║    Выход     ║" << std::endl;
	std::cout << pad << u8"╚══════════════╝" << std::endl;

	CommandsMenu result;
	bool exitFromCycl = false;
	do {

		PhysicCoordinateCell consoleCoord = handlerClickes->clickToConsole();

		if (consoleCoord.x >= MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS &&
			consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS) {
			if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY 
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY) {
				result = playGame;
				exitFromCycl = true;
			}
			else if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT 
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT) {
				result = exitGame;
				exitFromCycl = true;
			}
		}
	} while (!exitFromCycl);

	handlerClickes->setCursorOnOldCoordinates();

	return result;
}

int Renderer::drawSettingsDifficulty() {
	handlerClickes->ClearConsole();

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
		PhysicCoordinateCell consoleCoord = handlerClickes->clickToConsole();

		if (consoleCoord.x >= MIN_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS &&
			consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS) {
			if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY) {
				result = randomDifficult.random(18,27);
				exitFromCycl = true;
			}
			else if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM) {
				result = randomDifficult.random(30, 40);
				exitFromCycl = true;
			}
			else if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD) {
				result = randomDifficult.random(41, 50);
				exitFromCycl = true;
			}
			else if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE) {
				result = randomDifficult.random(51, 60);
				exitFromCycl = true;
			}
			else if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK 
				&& consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK) {
				result = -1;
				exitFromCycl = true;
			}
		}
	} while (!exitFromCycl);

	handlerClickes->setCursorOnOldCoordinates();

	return result;
}

void Renderer::InitializeCoordinate() {
	coordinate.buttonBack = false;
	coordinate.sudokuNumbersAvailableToInput = -1;
	coordinate.tableCoord = -1;
}
