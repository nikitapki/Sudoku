#pragma once

#include "Config.hpp"
#include "MouseHandler.hpp"
#include <string>

class Screen
{
protected:
    std::shared_ptr<MouseHandler> handler;
    std::string pad;
public:
    Screen(std::shared_ptr<MouseHandler> h)
        : handler(std::move(h)), pad(BASE_OFFSET_X, ' ') { }
};
