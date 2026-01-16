#include "MenuRenderer.hpp"

CommandsMenu MenuRenderer::drawMenu() {
    handler->ClearConsole();

    std::wstring padW = L"                                          ";
    std::wcout << padW << L"╔══════════════╗" << std::endl;
    std::wcout << padW << L"║    Играть    ║" << std::endl;
    std::wcout << padW << L"╚══════════════╝" << std::endl;
    std::wcout << padW << L"╔══════════════╗" << std::endl;
    std::wcout << padW << L"║    Выход     ║" << std::endl;
    std::wcout << padW << L"╚══════════════╝" << std::endl;

    while (true) {
        PhysicCoordinateCell coord = handler->clickToConsole();

        // Обработка кликов по кнопкам
        for (std::unique_ptr<IButton>& button : buttonsMainMenu) {
            if (button->contains(coord.getX(), coord.getY())) {
                //button->onClick();
                if (dynamic_cast<PlayButton*>(button.get())) {
                    return CommandsMenu::playGame;
                }
                if (dynamic_cast<ExitButton*>(button.get())) {
                    return CommandsMenu::exitGame;
                }
            }
        }
    }
}

int MenuRenderer::drawSettingsDifficulty() {
    handler->ClearConsole();

    std::wstring padW = L"                                          ";
    std::wcout << padW << L"╔═════════════════╗" << std::endl;
    std::wcout << padW << L"║   Легкий        ║" << std::endl;
    std::wcout << padW << L"╚═════════════════╝" << std::endl;
    std::wcout << padW << L"╔═════════════════╗" << std::endl;
    std::wcout << padW << L"║   Средний       ║" << std::endl;
    std::wcout << padW << L"╚═════════════════╝" << std::endl;
    std::wcout << padW << L"╔═════════════════╗" << std::endl;
    std::wcout << padW << L"║   Сложный       ║" << std::endl;
    std::wcout << padW << L"╚═════════════════╝" << std::endl;
    std::wcout << padW << L"╔═════════════════╗" << std::endl;
    std::wcout << padW << L"║   Невозможный   ║" << std::endl;
    std::wcout << padW << L"╚═════════════════╝" << std::endl;
    std::wcout << padW << L"╔═════════════════╗" << std::endl;
    std::wcout << padW << L"║   Вернуться     ║" << std::endl;
    std::wcout << padW << L"╚═════════════════╝" << std::endl;

    while (true) {
        PhysicCoordinateCell coord = handler->clickToConsole();

        // Обработка кликов по уровням сложности
        for (std::unique_ptr<IButton>& button: buttonsDifficultyMenu) {
            if (button->contains(coord.getX(), coord.getY())) {
                //button->onClick();

                if (dynamic_cast<DifficultyEasyButton*>(button.get())) {
                    return randomDifficult.random(18, 27);
                }
                else if (dynamic_cast<DifficultyMediumButton*>(button.get())) {
                    return randomDifficult.random(30, 40);
                }
                else if (dynamic_cast<DifficultyHardButton*>(button.get())) {
                    return randomDifficult.random(41, 50);
                }
                else if (dynamic_cast<DifficultyImpossibleButton*>(button.get())) {
                    return randomDifficult.random(51, 60);
                }
                else if (dynamic_cast<DifficultyBackButton*>(button.get())) {
                    return -1;
                }
            }
        }
    }
}
