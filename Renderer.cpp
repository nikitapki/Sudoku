#include "Renderer.hpp"

typeCoordinate translatorСonsoleToTableCoords(PhysicCoordinateCell consoleCoord) {
	
	typeCoordinate result;

	if (consoleCoord.y % 2 != 0 && consoleCoord.y <= 17 && consoleCoord.y >= 1) {
		if (consoleCoord.x % 4 != 0 && consoleCoord.x <= 36 && consoleCoord.x >= 1) {
			result.tableCoord = consoleCoord.y * SIZE_SUDOKU + consoleCoord.x;
		}
	}

	if (consoleCoord.y == 20) {
		if (consoleCoord.x % 4 != 0 && consoleCoord.x <= 36 && consoleCoord.x >= 1) {
			result.sudokuNumbersAvailableToInput = consoleCoord.x + 1;
		}
	}

	else {
		result.tableCoord = -1;
		result.sudokuNumbersAvailableToInput = -1;
	}

	return result;
}

// Отрисовка изначальной игры 
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

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Сохранение изначальной позиции курсора
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	COORD oldPos = csbi.dwCursorPosition;

	COORD pos;

	// Сделать правильное заполнение, затем сделать одиночное перемещение (вычисление какое значение переписывать)
	//

	// Перед вызовом нужно задать значения в таблицу

	field.generateNewGame(15); // временно

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