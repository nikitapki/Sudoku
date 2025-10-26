#ifndef FIELD
#define FIELD

#include "Cell.hpp"

class Field
{
public:
	int size;
	Cell **cells;
	
	Field();

	void Initialize();
};

#endif // !FIELD