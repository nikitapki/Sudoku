#pragma once
#include "PhysicCoordinateCell.hpp"

class IInput {
public:
    virtual PhysicCoordinateCell getClick() = 0; // получить действие
    virtual ~IInput() = default;
};