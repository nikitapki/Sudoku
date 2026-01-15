#pragma once
#include "IInput.hpp"
#include "MouseHandler.hpp"
#include <memory>

class MouseInput : public IInput {
private:
    std::shared_ptr<MouseHandler> mouse;
public:
    MouseInput(std::shared_ptr<MouseHandler> m)
        : mouse(std::move(m)) {
    }

    PhysicCoordinateCell getClick() override {
        return mouse->clickToConsole(); // реальная работа тут
    }
};
