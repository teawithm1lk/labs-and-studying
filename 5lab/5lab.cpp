#include <iostream>
#pragma warning(disable:4996)

int const LINE = 5;
int const ROW = 5;

int getLinesOfDifferent(int array[][ROW], int line, int row);

void openPart1();

int getNumberOfShittyLines(int** array, int sizeOfSquareMatrix);

void openPart2();

void failInput();

int main()
{
	openPart1();

	openPart2();
}

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
					linesOfDifferentElements = 0;
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

void openPart1()
{
	int array[LINE][ROW] = { {1, 2, 3, 4, 5},
						{6, 7, 8, 9, 10},
						{11, 12, 13, 14, 15},
						{16, 17, 18, 19, 20},
						{21, 22, 23, 24, 25} };
	std::cout << getLinesOfDifferent(array, LINE, ROW);
}

int getNumberOfShittyLines(int** array, int sizeOfSquareMatrix)
{
	int numberOfUnusualLines = 0;
	for (int i = 0; i < sizeOfSquareMatrix; i++)
	{
		for (int j = 1; j < sizeOfSquareMatrix; j++)
		{
			if (array[i][j] == array[i][j - 1])
			{
				break;
			}
			else if (j == sizeOfSquareMatrix - 1)
			{
				numberOfUnusualLines++;
			}
		}
	}
	return numberOfUnusualLines;
}

void openPart2()
{
	freopen("input.txt", "r", stdin);
	int numberRowsAndLines;
	std::cin >> numberRowsAndLines;
	failInput();
	int** dynamicArray = new int* [numberRowsAndLines];
	for (int i = 0; i < numberRowsAndLines; i++)
	{
		dynamicArray[i] = new int[numberRowsAndLines];
	}
	for (int i = 0; i < numberRowsAndLines; i++)
	{
		for (int j = 0; j < numberRowsAndLines; j++)
		{
			std::cin >> dynamicArray[i][j];
			failInput();
		}
	}
	fclose(stdin);
	freopen("output.txt", "w", stdout);
	std::cout << getNumberOfShittyLines(dynamicArray, numberRowsAndLines);
}

void failInput()
{
	if (std::cin.fail())
	{
		fclose(stdin);
		freopen("output.txt", "w", stdout);
		std::cout << "Failed. Try again with other input values.";
		exit(0);
	}
}
