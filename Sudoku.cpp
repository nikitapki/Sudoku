#include <iostream>
#include <locale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#include "Game.hpp"


// Функция вне класса, вычисляется ТОЛЬКО на компиляции (consteval)
// Функция была бы эффективна в случае разовой генерации сложности игры за 1 запуск
consteval int calculateCellsToRemove(int difficulty) {
    return difficulty == 0 ? 35 : // Легкая
        difficulty == 1 ? 45 : // Средняя
        difficulty == 2 ? 50 : // Сложная
        55; // Невозможная
}

// Класс с constexpr конструктором и методами
class SudokuConfig {
public:
    // constexpr конструктор - вычисляется на компиляции
    constexpr SudokuConfig()
        : minCells(17), // Минимум клеток для валидной судоку
        maxRemove(calculateCellsToRemove(2)),
        boardSize(9) {
    }

    // constexpr метод - может вызываться на компиляции
    constexpr int getDifficultyCells(int level) const {
        return minCells + level * 5;
    }

    constexpr int totalCells() const {
        return boardSize * boardSize;  // 81 - известно на компиляции
    }

private:
    int minCells, maxRemove, boardSize;
};


int main() {
	setlocale(LC_ALL, ".UTF8");

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Game startGame;
}
