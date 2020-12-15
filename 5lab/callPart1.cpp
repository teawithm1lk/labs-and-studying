#include <iostream>

int const LINE = 5;
int const ROW = 5;

int getLinesOfDifferent(int array[][ROW], int line, int row)
{
	int linesOfDifferentElements = 0;
	bool isExit = true;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (array[i][j] == array[i][k])
				{
					isExit = 0;
					break;
				}
			}
			if (!isExit)
			{
				isExit = true;
				break;
			}
			if (isExit and (j == row - 1))
			{
				linesOfDifferentElements++;
			}
		}
	}
	return linesOfDifferentElements;
}

void callPart1()
{
	int array[LINE][ROW] = { {1, 2, 3, 4, 5},
						{6, 7, 8, 9, 10},
						{11, 12, 13, 14, 15},
						{16, 17, 18, 19, 20},
						{21, 22, 23, 24, 25} };
	std::cout << getLinesOfDifferent(array, LINE, ROW);
}
