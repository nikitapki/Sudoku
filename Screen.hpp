#pragma once

#include "Config.hpp"
#include "MouseHandler.hpp"
#include <string>

class Screen {
protected:
    std::shared_ptr<MouseHandler> handler;
    std::string pad;
public:
    Screen(std::shared_ptr<MouseHandler> h)
        : handler(std::move(h)), pad(BASE_OFFSET_X, ' ') { }

    // ВРЕМЕННО. Демонстрация функции, которая имеет возможность быть переопределенной
    // ----------------------
    Screen() = default; // конструктор по умолчанию

    virtual void draw(int num) {
        std::cout << num;
    }

    virtual void draw(double num) {
        std::cout << num;
    }

    // Абстрактная 
//    virtual void drawAbstract() = 0;
    // ----------------------
};

// ВРЕМЕННО. Демонстрация наследования абстрактного класса
// Он по-сути является интерфейсом, показывает какие классы можно переопределить 
// и не может быть объектом напрямую.
    // Если сделать действительно класс Screen абстрактным, 
    // то будет ошибка, так как в наследниках не реализована абстрактная функция. 
    // Чтобы избежать ошибку стоит или отказаться от абстракции или добавить функцию. (Была добавлена для примера).
        // Так же поскольку в MenuRenderer была реализована эта абстракция ошибка при создании этого объекта не вызывается.
// ----------------------
//class MenuScreen : public Screen {
//    MenuController& menu;
//public:
//    MenuScreen(MenuController& m) : menu(m) { }
//    void drawAbstract() override { 
//        std::cout << "Своя реализация метода";
//    }
//};
// ----------------------
