#pragma once

class IButton {
public:
    virtual int getXStart() = 0; // Получить левую границу
    virtual int getXEnd() = 0; // Получить правую границу
    virtual int getYStart() = 0; // Верхняя граница
    virtual int getYEnd() = 0; // Нижняя граница

    // Действие при клике
    virtual void onClick() = 0; // Что делает кнопка

    // Проверка попадания клика
    virtual bool contains(const int x, const int y) = 0;
    
    virtual ~IButton() = default;
};
