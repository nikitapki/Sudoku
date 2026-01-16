#pragma once

#include "Screen.hpp"
#include "RandomLCG.hpp"
#include <vector>

#include "IButton.hpp"

#include "PlayButton.hpp"
#include "ExitButton.hpp"

#include "DifficultyEasyButton.hpp"
#include "DifficultyMediumButton.hpp"
#include "DifficultyHardButton.hpp"
#include "DifficultyImposibleButton.hpp"
#include "DifficultyBackButton.hpp"

enum class CommandsMenu {
    playGame = 1,
    exitGame = 2
};

class MenuRenderer : public Screen {
private:
    std::vector<std::unique_ptr<IButton>> buttonsMainMenu;
    std::vector<std::unique_ptr<IButton>> buttonsDifficultyMenu;

    RandomLCG randomDifficult;

public:
    MenuRenderer(std::shared_ptr<MouseHandler> handler)
        : Screen(std::move(handler)) {
        
        buttonsMainMenu.push_back(std::make_unique<PlayButton>());
        buttonsMainMenu.push_back(std::make_unique<ExitButton>());

        buttonsDifficultyMenu.push_back(std::make_unique<DifficultyEasyButton>());
        buttonsDifficultyMenu.push_back(std::make_unique<DifficultyMediumButton>());
        buttonsDifficultyMenu.push_back(std::make_unique<DifficultyHardButton>());
        buttonsDifficultyMenu.push_back(std::make_unique<DifficultyImpossibleButton>());
        buttonsDifficultyMenu.push_back(std::make_unique<DifficultyBackButton>());

    }   // вызов конструктора базового класса

    CommandsMenu drawMenu();

    int drawSettingsDifficulty(); // возвращает quantityRemoves или -1
};
