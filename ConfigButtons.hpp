#pragma once
#include "Config.hpp"

// Кнопки для отрисовки меню

constexpr int MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS = 0 + BASE_OFFSET_X; // Максимальная длина кнопок
constexpr int MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS = 15 + BASE_OFFSET_X; // Максимальная длина кнопок

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY = 0 + BASE_OFFSET_Y; // Для кнопки начала игры от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_PLAY = 2 + BASE_OFFSET_Y; // Для кнопки начала игры до по Y

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT = 3 + BASE_OFFSET_Y; // Для кнопки выхода от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT = 5 + BASE_OFFSET_Y; // Для кнопки выхода до по Y

// Кнопки для отрисовки меню выбора сложности

constexpr int MIN_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS = 0 + BASE_OFFSET_X; // Максимальная длина кнопок
constexpr int MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS = 19 + BASE_OFFSET_X; // Максимальная длина кнопок

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY = 0 + BASE_OFFSET_Y; // Для кнопки легкая сложность от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_EASY = 2 + BASE_OFFSET_Y; // Для кнопки легкая сложность до по Y

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM = 3 + BASE_OFFSET_Y; // Для кнопки средняя сложность от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_MEDIUM = 5 + BASE_OFFSET_Y; // Для кнопки средняя сложность до по Y

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD = 6 + BASE_OFFSET_Y; // Для кнопки сложная сложность от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD = 8 + BASE_OFFSET_Y; // Для кнопки сложная сложность до по Y

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE = 9 + BASE_OFFSET_Y; // Для кнопки невозможная сложность от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_IMPOSIBLE = 11 + BASE_OFFSET_Y; // Для кнопки невозможная сложность до по Y

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK = 12 + BASE_OFFSET_Y; // Для кнопки возврата от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_BACK = 14 + BASE_OFFSET_Y; // Для кнопки возврата до по Y


// Кнопка для возврата из игры в главное меню
constexpr int MIN_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK = 43 + BASE_OFFSET_X; // Для кнопки возврата от по X
constexpr int MAX_X_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK = 61 + BASE_OFFSET_X; // Для кнопки возврата до по X

constexpr int MIN_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK = 0 + BASE_OFFSET_Y; // Для кнопки возврата от по Y
constexpr int MAX_Y_FROM_CONSOLE_COLUMN_SUDOKU_BUTTON_BACK = 2 + BASE_OFFSET_Y; // Для кнопки возврата до по Y
