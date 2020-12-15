#include <iostream>
#include <fstream>
#include "mainFunctions.h"

int main()
{
	MyString fileName;
	std::ifstream inProgram;
	try
	{
		std::cout << "Please, entry name of your file (.txt format): ";
		std::cin >> fileName;
		inProgram.open(fileName.get());
		if (!inProgram.is_open())
		{
			throw "Error! File does not exist!";
		}
		if (inProgram.get() == EOF)
		{
			throw "Error! File is empty!";
		}
		inProgram.unget();
		Dynamic<Student> students;
		while (!inProgram.eof())
		{
			Student inputStudent;
			char symbol = inProgram.get();
			if (symbol == ' ' || symbol == '\n' || symbol == '\t')
			{
				symbol = inProgram.get();
			}
			inProgram.unget();
			inProgram >> inputStudent;
			students.push_back(inputStudent);
		}
		inProgram.close();
		outputSortedArray(students);
	}
	catch (const char* exception)
	{
		inProgram.close();
		std::cerr << exception;
	}
}