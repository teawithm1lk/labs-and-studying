#include <iostream>
#pragma warning(disable:4996)

int getNumberOfDynamicLines(int** array, int sizeOfSquareMatrix)
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

void failInputByNegativeNumber(int number)
{
	if (number <= 0)
	{
		fclose(stdin);
		freopen("output.txt", "w", stdout);
		std::cout << "Failed. Try again with other input values.";
		exit(0);
	}
}

void callPart2()
{
	freopen("input.txt", "r", stdin);
	int numberRowsAndLines;
	std::cin >> numberRowsAndLines;
	failInput();
	failInputByNegativeNumber(numberRowsAndLines);
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
	std::cout << getNumberOfDynamicLines(dynamicArray, numberRowsAndLines);
}