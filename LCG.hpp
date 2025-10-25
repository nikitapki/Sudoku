#ifndef LCG_RANDOM_GENERATOR
#define LCG_RANDOM_GENERATOR

class LCG
{
private:
	unsigned int state;

public:
	unsigned int random(unsigned int seed, int min, int max);

	void setState(unsigned int seed);
};

#endif // !LCG_RANDOM_GENERATOR