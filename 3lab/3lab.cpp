#include <iostream>
#include <time.h>
#pragma warning(disable : 4996)

int getNumbersForDynamicArray(int *dynamicArray, int arrayLength);

int getArrayLength();

std::string hasEqualNumbers(int* array, int arrayLength);

int main()
{
	setlocale(LC_ALL, "ru");
	srand(static_cast<unsigned int>(time(nullptr)));
	int staticArray[] = { 1, 1, 5, 7, 10, 5 };
	constexpr int STATIC_ARRAY_LENGTH = sizeof(staticArray) / sizeof(staticArray[0]);
	std::cout << "Объявленный статический массив:\n";
	for (int i = 0; i < STATIC_ARRAY_LENGTH; i++)
	{
		std::cout << staticArray[i] << ' ';
	}
	std::cout << ' ' << hasEqualNumbers(staticArray, STATIC_ARRAY_LENGTH) << '\n';


	std::cout << "Введите количество элементов в зарандомленном динамическом массиве: ";
	int dynamicArrayLength = getArrayLength();
	int* dynamicArray = new int[dynamicArrayLength];
	std::cout << "Динамический массив чисел:\n";
	getNumbersForDynamicArray(dynamicArray, dynamicArrayLength);
	std::cout << hasEqualNumbers(dynamicArray, dynamicArrayLength);
	delete[]dynamicArray;


	{
		freopen("input.txt", "r", stdin);
		int lengthOfArray;
		while (std::cin >> lengthOfArray)
		{
			if (std::cin.fail() or lengthOfArray <= 0)
			{	
				fclose(stdin);
				std::cerr << "Ошибка. Неверно введенный размер массива. Завершение программы.";
				exit(0);
			}
			int* massiveInFile = new int[lengthOfArray];
			std::cout << "\nМассив:\n";
			for (int i = 0; i < lengthOfArray; i++)
			{
				std::cin >> massiveInFile[i];
				if (std::cin.fail())
				{
					std::cerr << "Ошибка. Неверно введеный элемент массива. Завершение программы.";
					exit(0);
				}
				std::cout << massiveInFile[i] << " ";
			}
			std::cout << hasEqualNumbers(massiveInFile, lengthOfArray);
			delete[]massiveInFile;
		}
	}
}

int getArrayLength()
{
	int arrayLength;
	while (!(std::cin >> arrayLength) or arrayLength <= 0)
	{
		std::cin.clear();
		while(std::cin.get() != '\n');
		std::cout << "Ошибка.Введите целое положительное число: ";
	}
	return arrayLength;
}

int getNumbersForDynamicArray(int *dynamicArray, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		dynamicArray[i] = rand() % 1001;
		std::cout << dynamicArray[i] << ' ';
	}
	return 0;
}

std::string hasEqualNumbers(int *array, int arrayLength)
{
	for (int i = 0; i < arrayLength; i++)
	{
		for (int j = i + 1; j < arrayLength; j++)
		{
			if ((array[i] == array[j]) and (array[i] > 0))
			{
				return "\nЕсть повторяющиеся положительные числа.\n";
				break;
			}
		}
	}
	return "\nПовторяющиеся положительные числа отсутствуют.\n";
}
