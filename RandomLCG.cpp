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

// Функция поиска рандомного числа из заданного промежутка (не рассчитан на отрицательные числа)
unsigned int RandomLCG::random(int min, int max) {
	if (counter != max - min) {
		counter++;
	}
	else {
		counter = 0;
		installingSeed();
	}


	const unsigned int a = 1664525; // золотой стандарт для простых 32битных LCG
	const unsigned int c = 1013904223; // золотой стандарт для простых 32битных LCG 

	state = (a * state + c);

	return min + (state % (max - min + 1));
}

// Функция рандомно перемешивает заданный масив заданной длины
void RandomLCG::randomReverseMassive(int* massiveNums, int lenMassive) {
	int bufferNum, bufferIndex;
	for (int i = 0; i < lenMassive; i++) {
		bufferNum = massiveNums[i];
		bufferIndex = random(0, lenMassive-1);
		massiveNums[i] = massiveNums[bufferIndex];
		massiveNums[bufferIndex] = bufferNum;
	}
}