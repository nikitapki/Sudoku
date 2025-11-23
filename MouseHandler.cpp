#include "MouseHandler.hpp"

MouseHandler::MouseHandler() {
	hStdin = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(hStdin, &mode);
	SetConsoleMode(hStdin, mode | ENABLE_WINDOW_INPUT | 
		ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS & ~ENABLE_QUICK_EDIT_MODE);
}

PhysicCoordinateCell MouseHandler::clickToConsole() {

    PhysicCoordinateCell clickToField;

	while (true) {
        ReadConsoleInput(hStdin, irInBuf, SIZE_BUF, &cNumRead);

        for (DWORD i = 0; i < cNumRead; ++i) {
            if (irInBuf[i].EventType == MOUSE_EVENT) {
                MOUSE_EVENT_RECORD mer = irInBuf[i].Event.MouseEvent;

                bool isLeftClick = (mer.dwEventFlags == 0) && (mer.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED);

                if (isLeftClick) {
                    clickToField.x = mer.dwMousePosition.X;
                    clickToField.x = mer.dwMousePosition.Y;

                    return clickToField;
                }
            }
        }
	}
}