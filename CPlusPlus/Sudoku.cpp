#include <iostream>
#include <locale>
#include <windows.h>
#include <io.h>
#include <fcntl.h>

#include "Game.hpp"

int main() {
	setlocale(LC_ALL, ".UTF8");

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	Game startGame;
}
