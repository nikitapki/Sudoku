#ifndef CONTROL_GAME
#define CONTROL_GAME

#include "Config.hpp"
#include "Manager.hpp"
#include "Field.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include "MouseHandler.hpp"

// Не забыть убрать is_selected от прошлой игры, чтобы не выделялась ячейка сразу

class Game {
private:
	Manager field;
	Renderer render;
	MouseHandler handlerClickes;

public:
	Game();

};

#endif // !CONTROL_GAME