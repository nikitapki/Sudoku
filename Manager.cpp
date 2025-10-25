#include "Manager.hpp"

unsigned int Manager::random(unsigned int seed, int min, int max) {

	const unsigned int a = 1664525; // золотой стандарт для простых 32битных LCG
	const unsigned int c = 1013904223; // золотой стандарт для простых 32битных LCG 

	state = (a * state + c);

	return min + (state % (max - min + 1));
}

void Manager::setState(unsigned int seed) {
	state = seed;
}