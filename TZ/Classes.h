#pragma once

class Map
{
	int x_position = 10;
	int y_position = 10;
	int map[6][5] = {1, -1, 2, -1, 3,
					 2, -1, 3, -1, 1,
					 3,  0, 2,  0, 2,
					 1, -1, 1, -1, 3,
					 3,  0, 2,  0, 1,
					 1, -1, 3, -1, 2};
public:
	int get_x_position()
	{
		return x_position;
	}
	int get_y_position()
	{
		return y_position;
	}
	int get_elem(int i, int j)
	{
		return map[i][j];
	}
	void set_x_position(int digit)
	{
		x_position = digit;
	}
	void set_y_position(int digit)
	{
		y_position = digit;
	}
	void set_elem(int i, int j, int elem)
	{
		map[i][j] = elem;
	}
};