#pragma once

#include "IButton.hpp"
#include "ConfigButtons.hpp"

class DifficultyHardButton : public IButton {
public:
    int getXStart() override {
        return MIN_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS;
    }
    int getXEnd() override {
        return MAX_X_FROM_CONSOLE_ROW_MENU_SETTINGS_DIFFICULTIES_BUTTONS;
    }
    int getYStart() override {
        return MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD;
    }
    int getYEnd() override {
        return MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_DIFFICULT_HARD;
    }

    void onClick() override {}

    bool contains(const int x, const int y) override {
        return x >= getXStart() && x <= getXEnd() &&
            y >= getYStart() && y <= getYEnd();
    }
};
