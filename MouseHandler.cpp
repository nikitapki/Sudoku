#include "MouseHandler.hpp"

MouseHandler::MouseHandler() {
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, (mode | ENABLE_WINDOW_INPUT | 
		ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS) & ~ENABLE_QUICK_EDIT_MODE);


    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    oldPos = csbi.dwCursorPosition;
    saved_attributes = csbi.wAttributes;
}

PhysicCoordinateCell MouseHandler::clickToConsole() {

    PhysicCoordinateCell clickToField{ 0,0 };

	while (true) {
        ReadConsoleInput(hStdin, irInBuf, SIZE_BUF, &cNumRead);

        for (DWORD i = 0; i < cNumRead; ++i) {
            if (irInBuf[i].EventType == MOUSE_EVENT) {
                MOUSE_EVENT_RECORD mer = irInBuf[i].Event.MouseEvent;

                bool isLeftClick = (mer.dwEventFlags == 0) && (mer.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED);

                if (isLeftClick) {
                    clickToField.x = mer.dwMousePosition.X;
                    clickToField.y = mer.dwMousePosition.Y;
                    return clickToField;
                }
            }
        }
	}
}


void MouseHandler::ClearConsole() {

    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD charsWritten;

    // Заполнить всё пробелами
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, oldPos, &charsWritten);
    // Восстановить атрибуты
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, oldPos, &charsWritten);

    setCursorOnOldCoordinates();
}

void MouseHandler::setCursorOnCoordinates(PhysicCoordinateCell coord) {
    pos.X = coord.x;
    pos.Y = coord.y;
    SetConsoleCursorPosition(hConsole, pos);
}

void MouseHandler::setCursorOnOldCoordinates() {
    SetConsoleCursorPosition(hConsole, oldPos);
}

void MouseHandler::setColorOnConsole(WORD colors) {
    SetConsoleTextAttribute(hConsole, colors);
}

void MouseHandler::setStandartedColorOnConsole() {
    SetConsoleTextAttribute(hConsole, saved_attributes);
}
