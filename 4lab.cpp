#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#pragma warning(disable:4996)

bool functionC(char* input, int sizeArray);

bool functionString(const std::string& input, int length);

void callPartC();

void callPartString();

int main() 
{
	callPartC();
	std::cout << '\n';
	callPartString();
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

void callPartC()
{
	setlocale(LC_ALL, "ru");
	freopen("inputC.txt", "r", stdin);
	int sizeOfLine;
	std::cin >> sizeOfLine;
	if (std::cin.fail() or sizeOfLine <= 0)
	{
		std::cerr << "Îøèáêà ââîäà ðàçìåðà ìàññèâà.";
		exit(0);
	}
	sizeOfLine++;
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
		std::cout << "Â äàííîé ñòðîêå åñòü òàêàÿ ïàðà ñèìâîëîâ.";
	}
	else
	{
		std::cout << "Â äàííîé ñòðîêå íåò òàêîé ïàðû ñèìâîëîâ.";
	}
	delete[]inputArray;

}

void callPartString()
{
	std::ifstream filein("input.txt");
	std::string inputString;
	filein.open("inputString.txt");
	while (filein)
	{
		std::getline(filein, inputString);
	}
	std::cout << inputString << '\n';
	filein.close();
	unsigned int lengthOfLine = inputString.length();
	if (functionString(inputString, lengthOfLine))
	{
		std::cout << "Â äàííîé ñòðîêå åñòü òàêàÿ ïàðà ñèìâîëîâ.";
	}
	else
	{
		std::cout << "Â äàííîé ñòðîêå íåò òàêîé ïàðû ñèìâîëîâ.";
	}
}
