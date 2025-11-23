#ifndef RENDERER_FIELD
#define RENDERER_FIELD

#include <windows.h>

#include "Manager.hpp"
#include "MouseHandler.hpp"



class Renderer {

public:
	void drawElementaryField();

	void translator—onsoleToTableCoords();

	Manager field;

};

#endif // !RENDERER_FIELD