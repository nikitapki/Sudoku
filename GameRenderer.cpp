#include "GameRenderer.hpp"

void GameRenderer::correctionPosOnFieldFromDraw(PhysicCoordinateCell& consoleCoord) {
	PhysicCoordinateCell local = consoleCoord;
	local.x -= BASE_OFFSET_X;

	if (local.x % 2 == 0) {}
	else if (local.x % 4 == 3) {
		consoleCoord.x--;
	}
	else if (local.x % 4 == 1) {
		consoleCoord.x++;
	}
}

void GameRenderer::translatorСonsoleToTableCoords(PhysicCoordinateCell& consoleCoord) {
	PhysicCoordinateCell local = consoleCoord;
	local.x -= BASE_OFFSET_X;
	local.y -= BASE_OFFSET_Y;

	if (consoleCoord.y >= MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
		consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {

		if (consoleCoord.x >= MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
			consoleCoord.x <= MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {
			coordinate.buttonBack = true;
		}
	}

	if (local.y % 2 != 0 && consoleCoord.y <= MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU &&
		consoleCoord.y >= MIN_Y_FROM_CONSOLE_TABLES_SUDOKU) {

		if (local.x % 4 != 0 && consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord.x >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.tableCoord = local.y / 2 * SIZE_SUDOKU + local.x / 4;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}

	if (consoleCoord.y == Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU) {

		if (local.x % 4 != 0 && consoleCoord.x <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord.x >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.sudokuNumbersAvailableToInput = local.x / 4 + 1;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}
}

PhysicCoordinateCell GameRenderer::translatorTableToConsoleCoords(int coordinateCell) {
	PhysicCoordinateCell coord{ 0 };
	coord.y = coordinateCell / SIZE_SUDOKU * 2 + 1 + BASE_OFFSET_Y;
	coord.x = coordinateCell % SIZE_SUDOKU * 4 + 3 + BASE_OFFSET_X;

	return coord;
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
void GameRenderer::drawElementaryField() {

	InitializeCoordinate();

	handler->ClearConsole();

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
			handler->setCursorOnCoordinates(consoleCoord);

			coordCell = ((i - 1) / 2) * SIZE_SUDOKU + ((j - 3) / 4);

			if (cell(*field, coordCell).is_fixed) {
				std::cout << "\b" << cell(*field, coordCell).value;
			}
		}
	}
	handler->setCursorOnOldCoordinates();
}

void GameRenderer::highlightMiniTableNumber(PhysicCoordinateCell consoleCoord) {
	// Удаление старого выделения
	if (field->pastValueTableNumbers != -1) {
		PhysicCoordinateCell coordMiniTable;
		coordMiniTable.y = Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU;
		coordMiniTable.x = BASE_OFFSET_X + field->pastValueTableNumbers * 4 - 2;

		handler->setCursorOnCoordinates(coordMiniTable);

		std::cout << "\b" << " " << field->pastValueTableNumbers << " ";
	}

	// Установка нового выделения
	handler->setCursorOnCoordinates(consoleCoord);

	handler->setColorOnConsole(BACKGROUND_INTENSITY);

	std::cout << "\b" << " " << coordinate.sudokuNumbersAvailableToInput << " ";

	handler->setStandartedColorOnConsole();
}

void GameRenderer::highlightFieldCellsForNumber() {
	PhysicCoordinateCell coordinatesNotPermanent; // не постоянные координаты
	for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {

		coordinatesNotPermanent = translatorTableToConsoleCoords(i);;

		handler->setCursorOnCoordinates(coordinatesNotPermanent);

		if (field->compareNums(coordinate.sudokuNumbersAvailableToInput, cell(*field, i).value) &&
			cell(*field, i).is_fixed) {
			handler->setColorOnConsole(BACKGROUND_INTENSITY);

			std::cout << "\b\b" << " " << cell(*field, i).value << " ";

			handler->setStandartedColorOnConsole();
		}
		else {
			if (field->compareNums(field->pastValueTableNumbers, cell(*field, i).value) &&
				cell(*field, i).is_fixed) {
				std::cout << "\b\b" << " " << cell(*field, i).value << " ";
			}
		}
	}
}

bool GameRenderer::tryPlaceValueInCell(PhysicCoordinateCell consoleCoord) {
	if (coordinate.tableCoord < 0 || coordinate.tableCoord >= SIZE_SUDOKU_N_X_N) {
		return false;
	}

	if (field->checkInputValueInCell(coordinate.tableCoord, coordinate.sudokuNumbersAvailableToInput)) {
		handler->setCursorOnCoordinates(consoleCoord);

		handler->setColorOnConsole(BACKGROUND_INTENSITY);

		field->pastValueCell = coordinate.tableCoord;
		field->counterFixedCells(cell(*field, coordinate.tableCoord).value);

		handler->setStandartedColorOnConsole();

		return true;
	}
	else {
		return false;
	}
}

bool GameRenderer::drawValueCell() {

	PhysicCoordinateCell consoleCoord = handler->clickToConsole();

	translatorСonsoleToTableCoords(consoleCoord);

	if (coordinate.buttonBack) {
		coordinate.buttonBack = false; // чтобы при повторном заходе не выходило сразу
		return false;
	}


	else if (!field->compareNums(coordinate.sudokuNumbersAvailableToInput, field->pastValueTableNumbers)) {
		highlightMiniTableNumber(consoleCoord);
		highlightFieldCellsForNumber();
	}


	else if (!(field->compareNums(coordinate.tableCoord, field->pastValueCell))) {

		if (tryPlaceValueInCell(consoleCoord)) {
			highlightFieldCellsForNumber();
		}
	}
	field->pastValueTableNumbers = coordinate.sudokuNumbersAvailableToInput;

	handler->setCursorOnOldCoordinates();

	return true;
}

void GameRenderer::InitializeCoordinate() {
	coordinate.buttonBack = false;
	coordinate.sudokuNumbersAvailableToInput = -1;
	coordinate.tableCoord = -1;
	field->pastValueCell = -1;
	field->pastValueTableNumbers = -1;
}