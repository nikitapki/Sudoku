#pragma once

#include "Config.hpp"
#include "Manager.hpp"
#include "Field.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include "MouseHandler.hpp"
#include "MenuController.hpp"

#include <chrono>

// Не забыть убрать is_selected от прошлой игры, чтобы не выделялась ячейка сразу

class Game {
private:
	Manager field;
	Renderer renderField;
	MouseHandler handlerClickes;
	MenuController menu;

	using Clock = std::chrono::steady_clock;
	Clock::time_point roundStart;

public:
	Game();

};