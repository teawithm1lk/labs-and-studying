#include <iostream>
#include <fstream>
#include "verifying.h"

int main()
{
	const int MAX_SIZE_OF_LINE = 65535;
	char someLine[MAX_SIZE_OF_LINE] = {};
	std::ifstream inprog;
	try 
	{
		inprog.open("input.txt");
		if (!inprog.is_open())
		{
			throw "Error! File is not found.";
		}
		if (inprog.peek() == EOF)
		{
			throw "Error! File is empty.";
		}
		while (!inprog.eof())
		{
			inprog.getline(someLine, MAX_SIZE_OF_LINE, '\n');
			char* linePointer = someLine;
			std::cout << (isReal(&linePointer) ? "Yes" : "No") << "\n";
		}
	}
	catch (const char* exception)
	{
		std::cerr << exception << '\n';
	}
	return 0;
}