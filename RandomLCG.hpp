#ifndef LCG_RANDOM_GENERATOR
#define LCG_RANDOM_GENERATOR

#include <ctime>

class RandomLCG
{
private:
	unsigned int state;

	// Сама инициализация seed
	void installingSeed();

public:
	// Инициализирую seed для дальнейшего использования
	RandomLCG();

	// Выберает случайное натуральное число в заданном диапазоне от min (включистельно) до max (включительно)
	unsigned int random(int min, int max);
};

#endif // !LCG_RANDOM_GENERATOR