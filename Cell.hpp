#ifndef CELL
#define CELL

class Cell
{
public:
	int value;
	int input_value;
	bool is_fixed;
	bool is_selected;
	int position_x;
	int position_y;

	bool rightInputValue();

	void SetValue(int newValue);
};

#endif // !CELL