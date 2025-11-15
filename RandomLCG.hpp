#ifndef LCG_RANDOM_GENERATOR
#define LCG_RANDOM_GENERATOR

#include <ctime>

class RandomLCG
{
private:
	unsigned int state;

	// Внутренняя реализация в самом классе, которая устанавливает Seed
	void installingSeed();

public:
	// Устанавливает Seed для какого-то действия
	// Seed - начальное состояние генератора, с которого запускается формула
	// Временной промежуток, который используется для реализации функции рандома с использованием алгоритма LCG
	// Каждый Seed имеет только одну последовательность чисел
	RandomLCG();

	// Выбирает случайное натуральное число в заданном диапазоне от min (включительно) до max (включительно)
	unsigned int random(int min, int max);
};

#endif // !LCG_RANDOM_GENERATOR