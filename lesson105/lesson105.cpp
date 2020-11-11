#include <iostream>

int schizophrenia(int number);

void outputBackward(int number);

void outputForward(int number);

int main()
{
	unsigned int n = 145123;
	//std::cout << schizophrenia(n);
	//outputBackward(n);
	//outputForward(n);
}

int schizophrenia(int number)
{
	if (number == 0)
	{
		return 0;
	}
	else
	{
		return number%10 + schizophrenia(number / 10);
	}
}

void outputBackward(int number)
{
	if (number == 0)
	{
		return;
	}
	std::cout << number % 10; 
	outputBackward(number / 10);
}

void outputForward(int number)
{
	int n = 0;
	int newNumber = 0;
	while (number != 0)
	{
		n = (n + number % 10)*10;
		number /= 10;
	}
	n /= 10;
	while (n != 0)
	{
		newNumber = (newNumber + n % 10) * 10;
		n /= 10;
	}
	newNumber /= 10;
	std::cout << newNumber;
}