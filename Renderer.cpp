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

	if (consoleCoord->y >= MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK && 
		consoleCoord->y <= MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {

		if (consoleCoord->x >= MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
			consoleCoord->x <= MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {
			coordinate.buttonBack = true;
		}
	}

	if (consoleCoord->y % 2 != 0 && consoleCoord->y <= MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU && 
		consoleCoord->y >= MIN_X_Y_FROM_CONSOLE_TABLES_SUDOKU) {
		
		if (consoleCoord->x % 4 != 0 && consoleCoord->x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord->x >= MIN_X_Y_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.tableCoord = consoleCoord->y / 2 * SIZE_SUDOKU + consoleCoord->x / 4;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}

	if (consoleCoord->y == Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU) {

		if (consoleCoord->x % 4 != 0 && consoleCoord->x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU && 
			consoleCoord->x >= MIN_X_Y_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.sudokuNumbersAvailableToInput = consoleCoord->x / 4 + 1;
			(coordinate.tableCoord)--;
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
	
	ClearConsole();

	std::cout << u8"\
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗     ╔═════════════════╗\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║     ║   Вернуться     ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣     ╚═════════════════╝\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n\
║   ║   ║   ║   ║   ║   ║   ║   ║   ║\n\
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";

	std::cout << u8"\
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n\
║ 1 ║ 2 ║ 3 ║ 4 ║ 5 ║ 6 ║ 7 ║ 8 ║ 9 ║\n\
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n";

	int coordCell;
	for (int i = 1; i < SIZE_SUDOKU * 2; i += 2) {
		
		for (int j = 3; j < SIZE_SUDOKU * 4; j += 4) {
			pos.Y = i;
			pos.X = j;
			SetConsoleCursorPosition(hConsole, pos);
			
			coordCell = ((i - 1) / 2) * SIZE_SUDOKU + ((j - 3) / 4);

			if (field->gridCells.field[coordCell].is_fixed) {
				std::cout << "\b" << field->gridCells.field[coordCell].value;
			}
		}
	}
	SetConsoleCursorPosition(hConsole, oldPos);
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
			pos.X = consoleCoord.x;
			pos.Y = consoleCoord.y;
			SetConsoleCursorPosition(hConsole, pos);

			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);

			pastValueCell = coordinate.tableCoord;
			field->counterFixedCells(field->gridCells.field[coordinate.tableCoord].value);

			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
	}
	
	PhysicCoordinateCell coordinatesNotPermanent; // не постоянные координаты
	for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {

		coordinatesNotPermanent = translatorTableToConsoleCoords(i);

		coord.X = coordinatesNotPermanent.x;
		coord.Y = coordinatesNotPermanent.y;
		SetConsoleCursorPosition(hConsole, coord);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		saved_attributes = csbi.wAttributes;

		if (coordinate.sudokuNumbersAvailableToInput == field->gridCells.field[i].value && field->gridCells.field[i].is_fixed) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY);

			std::cout << "\b\b" << " " << field->gridCells.field[i].value << " ";

			SetConsoleTextAttribute(hConsole, saved_attributes);
		}
		else {
			if (pastValueTableNumbers == field->gridCells.field[i].value && field->gridCells.field[i].is_fixed) {
				std::cout << "\b\b" << " " << field->gridCells.field[i].value << " ";
			}
		}
	}
	pastValueTableNumbers = coordinate.sudokuNumbersAvailableToInput;

	SetConsoleCursorPosition(hConsole, oldPos);

	return true;
}

PhysicCoordinateCell Renderer::translatorTableToConsoleCoords(int coordinateCell) {
	PhysicCoordinateCell coord{ 0 };
	coord.y = coordinateCell / SIZE_SUDOKU * 2 + 1;
	coord.x = coordinateCell % SIZE_SUDOKU * 4 + 3;

	return coord;
}

CommandsMenu Renderer::drawMenu() {
	ClearConsole();

	std::cout << u8"\
╔══════════════╗\n\
║    Играть    ║\n\
╚══════════════╝\n\
╔══════════════╗\n\
║    Выход     ║\n\
╚══════════════╝\n";

	CommandsMenu result;
	bool exitFromCycl = false;
	do {

		PhysicCoordinateCell consoleCoord = handlerClickes->clickToConsole();

		if (consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS) {
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

	SetConsoleCursorPosition(hConsole, oldPos);

	return result;
}

int Renderer::drawSettingsDifficulty() {
	ClearConsole();

	std::cout << u8"\
╔═════════════════╗\n\
║   Легкий        ║\n\
╚═════════════════╝\n\
╔═════════════════╗\n\
║   Средний       ║\n\
╚═════════════════╝\n\
╔═════════════════╗\n\
║   Сложный       ║\n\
╚═════════════════╝\n\
╔═════════════════╗\n\
║   Невозможный   ║\n\
╚═════════════════╝\n\
╔═════════════════╗\n\
║   Вернуться     ║\n\
╚═════════════════╝\n";

	int result;
	bool exitFromCycl = false;
	do {
		PhysicCoordinateCell consoleCoord = handlerClickes->clickToConsole();

		if (consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS) {
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

	SetConsoleCursorPosition(hConsole, oldPos);

	return result;
}

void Renderer::ClearConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

	DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD charsWritten;
	COORD home = { 0, 0 };

	// Заполнить всё пробелами
	FillConsoleOutputCharacter(hConsole, ' ', consoleSize, home, &charsWritten);
	// Восстановить атрибуты
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, home, &charsWritten);
	// Курсор в (0,0)
	SetConsoleCursorPosition(hConsole, home);
}
