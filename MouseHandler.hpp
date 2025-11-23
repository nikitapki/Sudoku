#ifndef MOUSE_HANDLER
#define MOUSE_HANDLER

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

public:
	MouseHandler();

	PhysicCoordinateCell clickToConsole();
};

#endif // !MOUSE_HANDLER