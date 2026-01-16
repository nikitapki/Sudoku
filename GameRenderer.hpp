#pragma once

#include "Screen.hpp"
#include "Manager.hpp"
#include "RandomLCG.hpp"
#include "GameCoordinate.hpp"
#include <vector>
#include "GameBackOnMainMenuButton.hpp"


// для отрисовки судоку

constexpr int MIN_X_FROM_CONSOLE_TABLES_SUDOKU = 1 + BASE_OFFSET_X; // Для полей и значений доступных для выбора от по X
constexpr int MIN_Y_FROM_CONSOLE_TABLES_SUDOKU = 1 + BASE_OFFSET_Y; // Для полей и значений доступных для выбора от по Y

constexpr int MAX_Y_FROM_CONSOLE_COLUMN_TABLE_SUDOKU = 17 + BASE_OFFSET_Y; // Для поля игры до по Y
constexpr int MAX_X_FROM_CONSOLE_ROW_TABLES_SUDOKU = 36 + BASE_OFFSET_X; // Для поля игры до по X

constexpr int Y_FROM_CONSOLE_COLUMN_TABLE_NUMS_SUDOKU = 20 + BASE_OFFSET_Y; // Для выбора значений, доступных для игры по Y

class GameRenderer : public Screen {
private:
    RandomLCG randomDifficult;
    GameCoordinate coordinate;
    std::shared_ptr<Manager> field;

    std::vector<std::unique_ptr<IButton>> gameButton;

    void correctionPosOnFieldFromDraw(PhysicCoordinateCell& consoleCoord);
    void translatorСonsoleToTableCoords(PhysicCoordinateCell& consoleCoord);
    PhysicCoordinateCell translatorTableToConsoleCoords(int coordinateCell);

    void highlightMiniTableNumber(PhysicCoordinateCell consoleCoord);
    void highlightFieldCellsForNumber();
    bool tryPlaceValueInCell(PhysicCoordinateCell consoleCoord);

public:
    GameRenderer(std::shared_ptr<Manager> f, std::shared_ptr<MouseHandler> handler)
        : Screen(std::move(handler)), field(std::move(f)) {

        gameButton.push_back(std::make_unique<GameBackOnMainMenuButton>());

    }  // вызов базового класса

    void InitializeCoordinate();
    void drawElementaryField();
    bool drawValueCell(); // true = ход обработан, false = нажата "назад"
};
