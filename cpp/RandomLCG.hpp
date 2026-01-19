#pragma once

#include <ctime>
#include "Config.hpp"

class RandomLCG
{
private:
	unsigned int state;

	int counter = 0;

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

	void randomReverseMassive(int* massiveNums, int lenMassive);

	std::unique_ptr<int[]> randomGenerateReverseMassive(int start, int end);
};
