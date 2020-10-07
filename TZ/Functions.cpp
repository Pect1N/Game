#include <iostream>
#include "Classes.h"


// check player win. return true, if elemeints in one of collons equal
int win_check(Map elem)
{
	int result = 1;
	int col = 0;

	for (col; col < 5; col += 2)
	{
		result = 1;
		for (int j = 1; j < 6; ++j)
		{
			if (elem.get_elem(col, 0) != elem.get_elem(j, col))
				result = 0;
		}
	}
	return result;
}