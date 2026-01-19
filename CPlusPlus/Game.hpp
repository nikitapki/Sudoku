#pragma once

#include "Config.hpp"
#include "Manager.hpp"
#include "Field.hpp"
#include "GameRenderer.hpp"
#include "MouseHandler.hpp"
#include "MenuController.hpp"

class Game {
private:
	std::shared_ptr<Manager> field;
	std::shared_ptr<MouseHandler> handlerClickes;

	GameRenderer renderField;
	MenuController menu;

public:
	Game();

};
