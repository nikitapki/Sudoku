#include "Renderer.hpp"

void Renderer::correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord) {
	int x = consoleCoord->x;

	if (consoleCoord->x % 2 == 0) { }
	else if (consoleCoord->x % 4 == 3) {
		consoleCoord->x -= 1;
	}
	else if (consoleCoord->x % 4 == 1) {
		consoleCoord->x += 1;
	}
}

void Renderer::translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord) {

	if (consoleCoord->y % 2 != 0 && consoleCoord->y <= 17 && consoleCoord->y >= 1) {
		if (consoleCoord->x % 4 != 0 && consoleCoord->x <= 36 && consoleCoord->x >= 1) {
			coordinate.tableCoord = consoleCoord->y / 2 * SIZE_SUDOKU + consoleCoord->x / 4;
			correctionPosOnFieldFromDraw(consoleCoord);
		}
	}

	if (consoleCoord->y == 20) {
		if (consoleCoord->x % 4 != 0 && consoleCoord->x <= 36 && consoleCoord->x >= 1) {
			coordinate.sudokuNumbersAvailableToInput = consoleCoord->x / 4 + 1;
			coordinate.tableCoord = -1;
		}
	}
}

// Отрисовка изначальной игры 
// Перед вызовом нужно задать значения в таблицу
void Renderer::drawElementaryField() {

	std::cout << u8"\
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n\
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

			if (field.gridCells.field[coordCell].is_fixed) {
				std::cout << "\b" << field.gridCells.field[coordCell].value;
			}
		}
	}
	SetConsoleCursorPosition(hConsole, oldPos);
}

void Renderer::drawValueCell() {

	PhysicCoordinateCell consoleCoord = handlerClickes.clickToConsole();

	translatorСonsoleToTableCoords(&consoleCoord);

	if (coordinate.tableCoord != -1) {
		if (field.checkInputValueInCell(coordinate.tableCoord, coordinate.sudokuNumbersAvailableToInput)) {
			pos.X = consoleCoord.x;
			pos.Y = consoleCoord.y;
			SetConsoleCursorPosition(hConsole, pos);

			std::cout << field.gridCells.field[coordinate.tableCoord].value;
		}
		SetConsoleCursorPosition(hConsole, oldPos);
	}
}