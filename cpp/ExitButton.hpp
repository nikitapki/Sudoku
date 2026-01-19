#pragma once

#include "IButton.hpp"
#include "ConfigButtons.hpp"

class ExitButton : public IButton {
public:
    int getXStart() override {
        return MIN_X_FROM_CONSOLE_ROW_MENU_BUTTONS;
    }
    int getXEnd() override {
        return MAX_X_FROM_CONSOLE_ROW_MENU_BUTTONS;
    }
    int getYStart() override {
        return MIN_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT;
    }
    int getYEnd() override {
        return MAX_Y_FROM_CONSOLE_COLUMN_MENU_BUTTON_EXIT;
    }

    void onClick() override {
        
    }

    bool contains(const int x, const int y) override {
        return x >= getXStart() && x <= getXEnd() &&
            y >= getYStart() && y <= getYEnd();
    }
};
