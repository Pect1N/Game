#include <iostream>
#include "Classes.h"


// check player win. return true, if elemeints in one of collons equal
int win_check(Map* elem)
{
	int result = 1;
	int col = 0;

	for (col = 0; col < 5; col += 2)
	{
		result = 1;
		for (int j = 1; j < 6; ++j)
		{
			if (elem->get_elem(0, col) != elem->get_elem(j, col))
				result = 0;
		}
	}
	return result;
}

void move(Map* elem, int i, int j, int dx, int dy)
{
	// pressed element on our map
	if (i >= 1 && i <= 5 && j >= 0 && j <= 4)
	{
		// move only if long press
		if (abs(dx) >= 20 || abs(dy) >= 20)
		{
			if (abs(dx) - abs(dy) > 0)
			{
				// move right, if dx < 0
				if (dx < 0)
				{
					if (elem->get_elem(i, j + 1) == 0 && j < 4)
					{
						int save = 0;
						save = elem->get_elem(i, j + 1);
						elem->set_elem(i, j + 1, elem->get_elem(i, j));
						elem->set_elem(i, j, save);
					}
				}
				//else move left
				else
				{
					if (elem->get_elem(i, j - 1) == 0 && j > 0)
					{
						int save = 0;
						save = elem->get_elem(i, j - 1);
						elem->set_elem(i, j - 1, elem->get_elem(i, j));
						elem->set_elem(i, j, save);
					}
				}
			}
			else
			{
				// move down, if dy < 0
				if (dy < 0)
				{
					if (elem->get_elem(i + 1, j) == 0 && i < 5)
					{
						int save = 0;
						save = elem->get_elem(i + 1, j);
						elem->set_elem(i + 1, j, elem->get_elem(i, j));
						elem->set_elem(i, j, save);
					}
				}
				// else move up
				else
				{
					if (elem->get_elem(i - 1, j) == 0 && i > 1)
					{
						int save = 0;
						save = elem->get_elem(i - 1, j);
						elem->set_elem(i - 1, j, elem->get_elem(i, j));
						elem->set_elem(i, j, save);
					}
				}
			}
		}
	}
}

void show_matrix(Map elem)
{
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			std::cout << elem.get_elem(i, j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}