#ifndef CELL
#define CELL

class Cell
{
private:
	int value;
public:
	int input_value;
	bool is_fixed;
	bool is_selected;
	int position_x;
	int position_y;

	Cell(int position_x, int position_y);

	bool rightInputValue();

	void SetValueCreate(int create_value);
};

#endif // !CELL