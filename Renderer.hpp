#ifndef RENDERER_FIELD
#define RENDERER_FIELD

#include <windows.h>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"

typedef struct {
	int tableCoord;
	int sudokuNumbersAvailableToInput;
} typeCoordinate;

class Renderer {
private:
	typeCoordinate coordinate{ -1,-1 };

	int inputValue = -1;

	HANDLE hConsole;
	COORD oldPos;
	COORD pos{ 0,0 };

	// Сохранение изначальной позиции курсора
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	void correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord);

public:
	Manager& field;
	MouseHandler& handlerClickes;


	Renderer(Manager& field, MouseHandler& handlerClickes) :
		field(field),
		handlerClickes(handlerClickes) {
	
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		oldPos = csbi.dwCursorPosition;
	}

	void drawElementaryField();

	void translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord);

	void drawValueCell();

};

#endif // !RENDERER_FIELD