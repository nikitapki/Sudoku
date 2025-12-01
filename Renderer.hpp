#pragma once

#include <windows.h>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"
#include "RandomLCG.hpp"

// для отрисовки судоку

#define MIN_X_Y_FROM_CONSOLE_TABLES_SUDOKU 1 // Для полей и значений доступных для выбора от по X и Y

#define MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU 17 // Для поля игры до по Y
#define MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU 36 // Для поля игры до по X

#define Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU 20 // Для выбора значений, доступных для игры по Y

#define MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 43 // Для кнопки возврата от по X
#define MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 61 // Для кнопки возврата до по X
#define MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 0 // Для кнопки возврата от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 2 // Для кнопки возврата до по Y


// для отрисовки меню

#define MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS 15 // Максимальная длина кнопок

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY 0 // Для кнопки начала игры от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY 2 // Для кнопки начала игры до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT 3 // Для кнопки выхода от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT 5 // Для кнопки выхода до по Y

// для отрисовки меню выбора сложности

#define MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS 19 // Максимальная длина кнопок

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY 0 // Для кнопки легкая сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY 2 // Для кнопки легкая сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM 3 // Для кнопки средняя сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM 5 // Для кнопки средняя сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD 6 // Для кнопки сложная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD 8 // Для кнопки сложная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 9 // Для кнопки невозможная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 11 // Для кнопки невозможная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 9 // Для кнопки невозможная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 11 // Для кнопки невозможная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK 12 // Для кнопки возврата от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK 14 // Для кнопки возврата до по Y

// временно тут
enum CommandsMenu {
	playGame = 1,
	exitGame = 2
};

// исправить событие уменьшение окна ( в будущем )

typedef struct {
	int tableCoord;
	int sudokuNumbersAvailableToInput;
	bool buttonBack;
} typeCoordinate;

class Renderer {
private:
	RandomLCG randomDifficult;

	typeCoordinate coordinate{ -1,-1,false };

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

	void initializeCoordinate();

	void drawElementaryField();

	bool drawValueCell();

	CommandsMenu drawMenu();

	int drawSettingsDifficulty();

	void ClearConsole();

	// Устанавливает базовую точку начала отрисовки 
	//void setBaseCursore();
};