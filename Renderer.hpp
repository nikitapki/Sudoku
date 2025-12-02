#pragma once

#include <windows.h>
#include <string>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"
#include "RandomLCG.hpp"

// для отрисовки судоку

#define MIN_X_FROM_CONSOLE_TABLES_SUDOKU 1 + BASE_OFFSET_X // Для полей и значений доступных для выбора от по X
#define MIN_Y_FROM_CONSOLE_TABLES_SUDOKU 1 + BASE_OFFSET_Y // Для полей и значений доступных для выбора от по Y

#define MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU 17 + BASE_OFFSET_Y // Для поля игры до по Y
#define MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU 36 + BASE_OFFSET_X// Для поля игры до по X

#define Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU 20 + BASE_OFFSET_Y // Для выбора значений, доступных для игры по Y

#define MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 43 + BASE_OFFSET_X // Для кнопки возврата от по X
#define MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 61 + BASE_OFFSET_X // Для кнопки возврата до по X
#define MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 0 + BASE_OFFSET_Y // Для кнопки возврата от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK 2 + BASE_OFFSET_Y // Для кнопки возврата до по Y


// для отрисовки меню

#define MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS 0 + BASE_OFFSET_X // Максимальная длина кнопок
#define MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS 15 + BASE_OFFSET_X // Максимальная длина кнопок

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY 0 + BASE_OFFSET_Y // Для кнопки начала игры от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY 2 + BASE_OFFSET_Y // Для кнопки начала игры до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT 3 + BASE_OFFSET_Y // Для кнопки выхода от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT 5 + BASE_OFFSET_Y // Для кнопки выхода до по Y

// для отрисовки меню выбора сложности

#define MIN_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS 0 + BASE_OFFSET_X // Максимальная длина кнопок
#define MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS 19 + BASE_OFFSET_X // Максимальная длина кнопок

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY 0 + BASE_OFFSET_Y // Для кнопки легкая сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY 2 + BASE_OFFSET_Y // Для кнопки легкая сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM 3 + BASE_OFFSET_Y // Для кнопки средняя сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM 5 + BASE_OFFSET_Y // Для кнопки средняя сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD 6 + BASE_OFFSET_Y // Для кнопки сложная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD 8 + BASE_OFFSET_Y // Для кнопки сложная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 9 + BASE_OFFSET_Y // Для кнопки невозможная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 11 + BASE_OFFSET_Y // Для кнопки невозможная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 9 + BASE_OFFSET_Y // Для кнопки невозможная сложность от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE 11 + BASE_OFFSET_Y // Для кнопки невозможная сложность до по Y

#define MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK 12 + BASE_OFFSET_Y // Для кнопки возврата от по Y
#define MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK 14 + BASE_OFFSET_Y // Для кнопки возврата до по Y

// Максимум в счетчике цифр для ввода 
#define MAX_NUM_IN_NUMS_MINI_TABLE 9

// временно тут
enum CommandsMenu {
	playGame = 1,
	exitGame = 2
};

enum ColorsFromWinAtribute
{
	bk_green = BACKGROUND_INTENSITY
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

	MouseHandler* handlerClickes;
	Manager* field = nullptr;

	std::string pad; // подушка для смещенной отрисовки

	void correctionPosOnFieldFromDraw(PhysicCoordinateCell* consoleCoord);

	void translatorСonsoleToTableCoords(PhysicCoordinateCell* consoleCoord);

	PhysicCoordinateCell translatorTableToConsoleCoords(int coordinateCell);


	void highlightMiniTableNumber(PhysicCoordinateCell consoleCoord);

	void highlightFieldCellsForNumber();

	bool tryPlaceValueInCell(PhysicCoordinateCell consoleCoord);

public:
	
	// Для отрисовки меню
	Renderer(MouseHandler* handlerClickes) :
		handlerClickes(handlerClickes) {
		pad.assign(BASE_OFFSET_X, ' ');
	}

	// Для отрисовки игрового поля
	Renderer(Manager* field, MouseHandler* handlerClickes) :
		field(field),
		handlerClickes(handlerClickes) {
		pad.assign(BASE_OFFSET_X, ' ');
	}

	void InitializeCoordinate();

	void drawElementaryField();

	bool drawValueCell();

	CommandsMenu drawMenu();

	int drawSettingsDifficulty();
};