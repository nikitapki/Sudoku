#pragma once

#include <windows.h>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"
#include "RandomLCG.hpp"

// временно
enum CommandsMenu {
	playGame = 1,
	exitGame = 2
};

// исправить событие уменьшение окна ( в будущем )

typedef struct {
	int tableCoord;
	int sudokuNumbersAvailableToInput;
} typeCoordinate;

class Renderer {
private:
	RandomLCG randomDifficult;

	typeCoordinate coordinate{ -1,-1 };

	// Для отображения позиции курсора
	HANDLE hConsole;
	COORD oldPos;
	COORD pos{ 0,0 };

	// Для отображения цвета
	COORD coord{ 0,0 };
	WORD saved_attributes;
	int pastValueCell = -1; // прошлое значение 
	int pastValueTableNumbers = -1;// прошлое значение таблицы с возможными значениями для судоку

	// Сохранение изначальной позиции курсора и изначального цвета
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	MouseHandler* handlerClickes;
	Manager* field = nullptr;

	void correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord);

	void translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord);

	PhysicCoordinateCell translatorTableToConsoleCoords(int coordinateCell);

public:
	
	// Для отрисовки меню
	Renderer(MouseHandler* handlerClickes) :
		handlerClickes(handlerClickes) {

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		oldPos = csbi.dwCursorPosition;
		saved_attributes = csbi.wAttributes;
	}

	// Для отрисовки игрового поля
	Renderer(Manager* field, MouseHandler* handlerClickes) :
		field(field),
		handlerClickes(handlerClickes) {
	
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		oldPos = csbi.dwCursorPosition;
		saved_attributes = csbi.wAttributes;
	}

	void drawElementaryField();

	void drawValueCell();

	CommandsMenu drawMenu();

	int drawSettingsDifficulty();

	void ClearConsole();
};