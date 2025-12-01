#pragma once

#include "Config.hpp"

typedef struct {
	SHORT x;
	SHORT y;
} PhysicCoordinateCell;

class MouseHandler {
private:
	HANDLE hStdin;
	DWORD mode;
	INPUT_RECORD irInBuf[SIZE_BUF];
	DWORD cNumRead;

	// Для отображения позиции курсора
	HANDLE hConsole;
	COORD oldPos;
	COORD pos{ 0,0 };

	// Для отображения цвета
	COORD coord{ 0,0 };
	WORD saved_attributes;

	// Сохранение изначальной позиции курсора и изначального цвета
	CONSOLE_SCREEN_BUFFER_INFO csbi;

public:
	MouseHandler();

	PhysicCoordinateCell clickToConsole();

	void ClearConsole();

	void setCursorOnCoordinates(PhysicCoordinateCell coord);

	void setCursorOnOldCoordinates();

	void setColorOnConsole(WORD colors);

	void setStandartedColorOnConsole();
};