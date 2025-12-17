#pragma once

#include "Config.hpp"
#include "Manager.hpp"
#include "Field.hpp"
#include "Renderer.hpp"
#include "MouseHandler.hpp"
#include "MenuController.hpp"

//#include <chrono>

// Не забыть убрать is_selected от прошлой игры, чтобы не выделялась ячейка сразу

class Game {
private:
	std::shared_ptr<Manager> field;
	std::shared_ptr<MouseHandler> handlerClickes;

	Renderer renderField;
	MenuController menu;

//	using Clock = std::chrono::steady_clock;
//	Clock::time_point roundStart;

public:
	Game();

};