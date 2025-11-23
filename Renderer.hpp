#ifndef RENDERER_FIELD
#define RENDERER_FIELD

#include <windows.h>

#include "Config.hpp"
#include "Manager.hpp"
#include "MouseHandler.hpp"

typedef struct {
	int tableCoord;
	int sudokuNumbersAvailableToInput;
} typeCoordinate;

class Renderer {

public:
	void drawElementaryField();

	MouseHandler handlerMouse;

	typeCoordinate translator—onsoleToTableCoords(PhysicCoordinateCell consoleCoord);

	Manager field;

};

#endif // !RENDERER_FIELD