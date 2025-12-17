#pragma once

#include "Screen.hpp"
#include "RandomLCG.hpp"

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

enum CommandsMenu {
    playGame = 1,
    exitGame = 2
};

class MenuRenderer : public Screen {
private:
    RandomLCG randomDifficult;

public:
    MenuRenderer(std::shared_ptr<MouseHandler> handler)
        : Screen(std::move(handler)) {
    }   // вызов конструктора базового класса

    CommandsMenu drawMenu();

    int drawSettingsDifficulty(); // возвращает quantityRemoves или -1
};
