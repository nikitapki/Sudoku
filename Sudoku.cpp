#include <iostream>
#include <locale>
#include <windows.h>

#include "Manager.hpp"
#include "Game.hpp"
#include "Renderer.hpp"
#include "MouseHandler.hpp"

int main() {
	setlocale(LC_ALL, ".UTF8");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);
	
	Game startGame;
}