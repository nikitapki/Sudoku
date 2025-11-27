#ifndef RENDERER_FIELD
#define RENDERER_FIELD

#include <windows.h>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"

// исправить событие уменьшение окна ( в будущем )

typedef struct {
	int tableCoord;
	int sudokuNumbersAvailableToInput;
} typeCoordinate;

class Renderer {
private:
	typeCoordinate coordinate{ -1,-1 };

	// Для отображения позиции курсора
	HANDLE hConsole;
	COORD oldPos;
	COORD pos{ 0,0 };

	// Для отображения цвета
	COORD coord;
	WORD saved_attributes;
	int pastValue = -1; // прошлое значение

	// Сохранение изначальной позиции курсора и изначального цвета
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	MouseHandler& handlerClickes;
	Manager& field;

	void correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord);

	void translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord);

	PhysicCoordinateCell translatorTableToConsoleCoords(int coordinateCell);

public:


	Renderer(Manager& field, MouseHandler& handlerClickes) :
		field(field),
		handlerClickes(handlerClickes) {
	
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		oldPos = csbi.dwCursorPosition;
	}

	void drawElementaryField();

	void drawValueCell();

};

#endif // !RENDERER_FIELD