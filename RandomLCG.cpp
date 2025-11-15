#include "RandomLCG.hpp"

// Устанавливает Seed для какого-то действия
// Seed - начальное состояние генератора, с которого запускается формула
// Временной промежуток, который используется для реализации функции рандома с использованием алгоритма LCG
// Каждый Seed имеет только одну последовательность чисел
RandomLCG::RandomLCG() {
	installingSeed();
}

// Внутренняя реализация в самом классе, которая устанавливает Seed
void RandomLCG::installingSeed() {
	state = time(nullptr);
}

// Функция поиска рандомного числа из заданного промежутка
unsigned int RandomLCG::random(int min, int max) {

	const unsigned int a = 1664525; // золотой стандарт для простых 32битных LCG
	const unsigned int c = 1013904223; // золотой стандарт для простых 32битных LCG 

	state = (a * state + c);

	return min + (state % (max - min + 1));
}