#include "Renderer.hpp"

void translatorСonsoleToTableCoords(PhysicCoordinateCell consoleCoord) {
	if (consoleCoord.y >= 0 && consoleCoord.y <= 18) {
		
	}
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