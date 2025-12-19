#include "GameRenderer.hpp"

void GameRenderer::correctionPosOnFieldFromDraw(PhysicCoordinateCell& consoleCoord) {
	PhysicCoordinateCell local = consoleCoord;
	local.calculationMinusX(BASE_OFFSET_X);

	if (local.getX() % 2 == 0) {}
	else if (local.getX() % 4 == 3) {
		consoleCoord.calculationMinusX(1);
	}
	else if (local.getX() % 4 == 1) {
		consoleCoord.calculationPlusX(1);
	}
}

void GameRenderer::translatorСonsoleToTableCoords(PhysicCoordinateCell& consoleCoord) {
	PhysicCoordinateCell local = consoleCoord;
	local.calculationMinusX(BASE_OFFSET_X);
	local.calculationMinusY(BASE_OFFSET_Y);

	if (consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
		consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {

		if (consoleCoord.getX() >= MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK &&
			consoleCoord.getX() <= MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK) {
			coordinate.setButtonBack(true);
		}
	}

	if (local.getY() % 2 != 0 && consoleCoord.getY() <= MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU &&
		consoleCoord.getY() >= MIN_Y_FROM_CONSOLE_TABLES_SUDOKU) {

		if (local.getX() % 4 != 0 && consoleCoord.getX() <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord.getX() >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.setTableCoord(local.getY() / 2 * SIZE_SUDOKU + local.getX() / 4);
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}

	if (consoleCoord.getY() == Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU) {

		if (local.getX() % 4 != 0 && consoleCoord.getX() <= MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU &&
			consoleCoord.getX() >= MIN_X_FROM_CONSOLE_TABLES_SUDOKU) {
			coordinate.setSudokuNumbersAvailableToInput(local.getX() / 4 + 1);
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}
}

PhysicCoordinateCell GameRenderer::translatorTableToConsoleCoords(int coordinateCell) {
	PhysicCoordinateCell coord;
	coord.setY(coordinateCell / SIZE_SUDOKU * 2 + 1 + BASE_OFFSET_Y);
	coord.setX(coordinateCell % SIZE_SUDOKU * 4 + 3 + BASE_OFFSET_X);

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
			consoleCoord.setY(i + BASE_OFFSET_Y);
			consoleCoord.setX(j + BASE_OFFSET_X);
			handler->setCursorOnCoordinates(consoleCoord);

			coordCell = ((i - 1) / 2) * SIZE_SUDOKU + ((j - 3) / 4);

			if (cell(*field, coordCell).getIs_fixed()) {
				std::cout << "\b" << cell(*field, coordCell).getValue();
			}
		}
	}
	handler->setCursorOnOldCoordinates();
}

void GameRenderer::highlightMiniTableNumber(PhysicCoordinateCell consoleCoord) {
	// Удаление старого выделения
	if (field->pastValueTableNumbers != -1) {
		PhysicCoordinateCell coordMiniTable;
		coordMiniTable.setY(Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU);
		coordMiniTable.setX(BASE_OFFSET_X + field->pastValueTableNumbers * 4 - 2);

		handler->setCursorOnCoordinates(coordMiniTable);

		std::cout << "\b" << " " << field->pastValueTableNumbers << " ";
	}

	// Установка нового выделения
	handler->setCursorOnCoordinates(consoleCoord);

	handler->setColorOnConsole(BACKGROUND_INTENSITY);

	std::cout << "\b" << " " << coordinate.getSudokuNumbersAvailableToInput() << " ";

	handler->setStandartedColorOnConsole();
}

void GameRenderer::highlightFieldCellsForNumber() {
	PhysicCoordinateCell coordinatesNotPermanent; // не постоянные координаты
	for (int i = 0; i < SIZE_SUDOKU * SIZE_SUDOKU; i++) {

		coordinatesNotPermanent = translatorTableToConsoleCoords(i);;

		handler->setCursorOnCoordinates(coordinatesNotPermanent);

		if (field->compareNums(coordinate.getSudokuNumbersAvailableToInput(), cell(*field, i).getValue()) &&
			cell(*field, i).getIs_fixed()) {
			handler->setColorOnConsole(BACKGROUND_INTENSITY);

			std::cout << "\b\b" << " " << cell(*field, i).getValue() << " ";

			handler->setStandartedColorOnConsole();
		}
		else {
			if (field->compareNums(field->pastValueTableNumbers, cell(*field, i).getValue()) &&
				cell(*field, i).getIs_fixed()) {
				std::cout << "\b\b" << " " << cell(*field, i).getValue() << " ";
			}
		}
	}
}

bool GameRenderer::tryPlaceValueInCell(PhysicCoordinateCell consoleCoord) {
	if (coordinate.getTableCoord() < 0 || coordinate.getTableCoord() >= SIZE_SUDOKU_N_X_N) {
		return false;
	}

	if (field->checkInputValueInCell(coordinate.getTableCoord(), coordinate.getSudokuNumbersAvailableToInput())) {
		handler->setCursorOnCoordinates(consoleCoord);

		handler->setColorOnConsole(BACKGROUND_INTENSITY);

		field->pastValueCell = coordinate.getTableCoord();
		field->counterFixedCells(cell(*field, coordinate.getTableCoord()).getValue());

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

	if (coordinate.getButtonBack()) {
		coordinate.setButtonBack(false); // чтобы при повторном заходе не выходило сразу
		return false;
	}


	else if (!field->compareNums(coordinate.getSudokuNumbersAvailableToInput(), field->pastValueTableNumbers)) {
		highlightMiniTableNumber(consoleCoord);
		highlightFieldCellsForNumber();
	}


	else if (!(field->compareNums(coordinate.getTableCoord(), field->pastValueCell))) {

		if (tryPlaceValueInCell(consoleCoord)) {
			highlightFieldCellsForNumber();
		}
	}
	field->pastValueTableNumbers = coordinate.getSudokuNumbersAvailableToInput();

	handler->setCursorOnOldCoordinates();

	return true;
}

void GameRenderer::InitializeCoordinate() {
	coordinate.initialiseCoordinate();
	field->pastValueCell = -1;
	field->pastValueTableNumbers = -1;
}
