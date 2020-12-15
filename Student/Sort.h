#ifndef SORT_H
#define SORT_H

#include <iostream>

template <class T>
void swap(T& object1, T& object2)
{
	T temp;
	temp = object1;
	object1 = object2;
	object2 = temp;
}

template <class T>
void sort(T& arrayOfObjects, size_t length)
{
	for (size_t i = 1; i < length; i++)
	{
		for (size_t j = i; j > 0 && arrayOfObjects[j - 1] > arrayOfObjects[j]; j--)
		{
			swap(arrayOfObjects[j - 1], arrayOfObjects[j]);
		}
	}
}

#endif