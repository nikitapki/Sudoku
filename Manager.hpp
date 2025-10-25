#ifndef MANAGER_SUDOKU
#define MANAGER_SUDOKU

class Manager
{
private:
	unsigned int state;

public:
	unsigned int random(unsigned int seed, int min, int max);

	void setState(unsigned int seed);
};

#endif // !MANAGER_SUDOKU