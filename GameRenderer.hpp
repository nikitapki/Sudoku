#pragma once

#include "Screen.hpp"
#include "Manager.hpp"
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

struct GameCoordinate {
    int tableCoord = -1;
    int sudokuNumbersAvailableToInput = -1;
    bool buttonBack = false;
};

class GameRenderer : public Screen {
private:
    RandomLCG randomDifficult;
    GameCoordinate coordinate;
    std::shared_ptr<Manager> field;

    void correctionPosOnFieldFromDraw(PhysicCoordinateCell& consoleCoord);
    void translatorСonsoleToTableCoords(PhysicCoordinateCell& consoleCoord);
    PhysicCoordinateCell translatorTableToConsoleCoords(int coordinateCell);

    void highlightMiniTableNumber(PhysicCoordinateCell consoleCoord);
    void highlightFieldCellsForNumber();
    bool tryPlaceValueInCell(PhysicCoordinateCell consoleCoord);

public:
    GameRenderer(std::shared_ptr<Manager> f, std::shared_ptr<MouseHandler> handler)
        : Screen(std::move(handler)), field(std::move(f)) {
    }  // вызов базового класса

    void InitializeCoordinate();
    void drawElementaryField();
    bool drawValueCell(); // true = ход обработан, false = нажата "назад"
};
