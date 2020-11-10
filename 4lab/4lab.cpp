#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#pragma warning(disable:4996)

bool functionC(char* input, int sizeArray);

bool functionString(const std::string& input, int length);

int main() 
{
	setlocale(LC_ALL, "ru");
	freopen("input.txt", "r", stdin);
	char inputSymbol;
	int sizeOfLine = 0;
	while (std::cin.get(inputSymbol))
	{
		sizeOfLine++;
	}
	fclose(stdin);
	freopen("input.txt", "r", stdin);
	char* inputArray = new char[sizeOfLine];
	getc(stdin);
	gets_s(inputArray, sizeOfLine);
	for (int i = 0; i < sizeOfLine; i++)
	{
		std::cout << inputArray[i];
	}
	std::cout << '\n';
	fclose(stdin);
	if (functionC(inputArray, sizeOfLine))
	{
		std::cout << "В данной строке есть такая пара символов.";
	}
	else
	{
		std::cout << "В данной строке нет такой пары символов.";
	}
	delete[]inputArray;

	std::cout << '\n';

	std::ifstream filein("input.txt");
	std::string inputString;
	filein.open("input.txt");
	while (filein)
	{
		std::getline(filein, inputString);
	}
	std::cout << inputString << '\n';
	filein.close();
	unsigned int lengthOfLine = inputString.length();
	if (functionString(inputString, lengthOfLine))
	{
		std::cout << "В данной строке есть такая пара символов.";
	}
	else
	{
		std::cout << "В данной строке нет такой пары символов.";
	}
}

bool functionC(char* input, int sizeArray)
{
	for (int i = 1; i < sizeArray; i++)
	{
		if (input[i] == input[i - 1])
		{
			return true;
		}
	}
	return false;
}

bool functionString(const std::string &input, int length)
{
	for (int i = 1; i < length; i++)
	{
		if (input[i] == input[i - 1])
		{
			return true;
		}
	}
	return false;
}