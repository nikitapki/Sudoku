#pragma once

#include <windows.h>
#include <iostream>

static constexpr int SIZE_SUDOKU = 9; // размер NxN судоку
static constexpr int SIZE_SQUARE_SUDOKU = 3; // размер nxn малого квадрата судоку
static constexpr int SIZE_COUNTER_IMPUT_NUMS = SIZE_SUDOKU + 1; // –азмер пол€ судоку (общий)
static constexpr int SIZE_SUDOKU_N_X_N = SIZE_SUDOKU * SIZE_SUDOKU; // –азмер всей судоку

static constexpr int SIZE_BUF = 128; // размер буфера 

static constexpr int BASE_OFFSET_Y = 5; // базовое смещение по X дл€ настройки расположени€ при отрисовке
static constexpr int BASE_OFFSET_X = 42; // базовое смещение по Y дл€ настройки расположени€ при отрисовке
