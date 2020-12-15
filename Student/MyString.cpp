#include <iostream>
#include "MyString.h"

MyString::MyString()
	{
		string_ = nullptr;
	}
MyString::MyString(const char* string)
	{
		size_t lengthString = 0;
		if (string != nullptr)
		{
			lengthString = strlen(string);
		}
		this->string_ = new char[lengthString + 1];
		for (int i = 0; i < lengthString; i++)
		{
			string_[i] = string[i];
		}
		string_[lengthString] = '\0';
	}
MyString::MyString(const MyString& object)
{
	size_t newLength = 0;
	if (object.string_ != nullptr)
	{
		newLength = strlen(object.string_);
	}
	this->string_ = new char[newLength + 1];
	for (int i = 0; i < newLength; i++)
	{
		string_[i] = object.string_[i];
	}
	string_[newLength] = '\0';
}
MyString::~MyString()
{
	delete[]string_;
}

MyString& MyString::operator= (const MyString& otherObject)
{
	delete[]this->string_;
	size_t lengthString;
	if (otherObject.string_ != nullptr)
	{
			lengthString = strlen(otherObject.string_);
			this->string_ = new char[lengthString+1];
			for (int i = 0; i < lengthString; i++)
			{
				this->string_[i] = otherObject.string_[i];
			}
			this->string_[lengthString] = '\0';
	}
	return *this;
}
MyString MyString::operator+ (const MyString& otherObject)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t otherLength = 0;
	if (otherObject.string_ != nullptr)
	{
		otherLength = strlen(otherObject.string_);
	}
	size_t summaryLength = currentLength + otherLength;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	for (size_t i = 0; i < otherLength; i++)
	{
		temp.string_[currentLength + i] = otherObject.string_[i];
	}
	temp.string_[summaryLength] = '\0';
	return temp;
}
MyString MyString::operator+ (const char* other)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t otherLength = 0;
	if (other != nullptr)
	{
		otherLength = strlen(other);
	}
	size_t summaryLength = currentLength + otherLength;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	for (size_t i = 0; i < otherLength; i++)
	{
		temp.string_[currentLength + i] = other[i];
	}
	temp.string_[summaryLength] = '\0';
	return temp;
}
MyString MyString::operator+ (const char symbol)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t summaryLength = currentLength + 1;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	temp.string_[summaryLength - 1] = symbol;
	temp.string_[summaryLength] = '\0';
	return temp;
}
MyString& MyString::operator+= (const MyString& otherObject)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t otherLength = 0;
	if (otherObject.string_ != nullptr)
	{
		otherLength = strlen(otherObject.string_);
	}
	size_t summaryLength = currentLength + otherLength;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	for (size_t i = 0; i < otherLength; i++)
	{
		temp.string_[currentLength + i] = otherObject.string_[i];
	}
	temp.string_[summaryLength] = '\0';
	delete[]this->string_;
	this->string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < summaryLength; i++)
	{
		this->string_[i] = temp.string_[i];
	}
	string_[summaryLength] = '\0';
	return *this;
}
MyString& MyString::operator+= (const char* other)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t otherLength = 0;
	if (other != nullptr)
	{
		otherLength = strlen(other);
	}
	size_t summaryLength = currentLength + otherLength;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	for (size_t i = 0; i < otherLength; i++)
	{
		temp.string_[currentLength + i] = other[i];
	}
	temp.string_[summaryLength] = '\0';
	delete[]this->string_;
	this->string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < summaryLength; i++)
	{
		this->string_[i] = temp.string_[i];
	}
	string_[summaryLength] = '\0';
	return *this;
}
MyString& MyString::operator+= (const char symbol)
{
	MyString temp;
	size_t currentLength = 0;
	if (this->string_ != nullptr)
	{
		currentLength = strlen(this->string_);
	}
	size_t summaryLength = currentLength + 1;
	temp.string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < currentLength; i++)
	{
		temp.string_[i] = this->string_[i];
	}
	temp.string_[summaryLength - 1] = symbol;
	temp.string_[summaryLength] = '\0';
	delete[]this->string_;
	this->string_ = new char[summaryLength + 1];
	for (size_t i = 0; i < summaryLength; i++)
	{
		this->string_[i] = temp.string_[i];
	}
	string_[summaryLength] = '\0';
	return *this;
}
bool MyString::operator== (const MyString& otherObject)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	size_t lengthOtherString = 0;
	if (otherObject.string_ != nullptr)
	{
		lengthOtherString = strlen(otherObject.string_);
	}
	if (lengthString == lengthOtherString)
	{
		for (int i = 0; i < lengthString; i++)
		{
			if (this->string_[i] == otherObject.string_[i])
			{
				continue;
			}
			else
			{
				break;
			}
			if (i == lengthString - 1)
			{
				return true;
			}
		}
	}
	return false;
}
bool MyString::operator== (const char* other)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	size_t lengthOtherString = 0;
	if (other != nullptr)
	{
		lengthOtherString = strlen(other);
	}
	if (lengthString == lengthOtherString)
	{
		for (int i = 0; i < lengthString; i++)
		{
			if (this->string_[i] == other[i])
			{
				continue;
			}
			else
			{
				break;
			}
			if (i == lengthString - 1)
			{
				return true;
			}
		}
	}
	return false;
}
bool MyString::operator== (const char symbol)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	if (lengthString == 1)
	{
		if (this->string_[0] == symbol)
		{
			return true;
		}
	}
	return false;
}
bool MyString::operator!= (const MyString& otherObject)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	size_t lengthOtherString = 0;
	if (otherObject.string_ != nullptr)
	{
		lengthOtherString = strlen(otherObject.string_);
	}
	if (lengthString == lengthOtherString)
	{
		for (int i = 0; i < lengthString; i++)
		{
			if (this->string_[i] == otherObject.string_[i])
			{
				continue;
			}
			else
			{
				break;
			}
			if (i == lengthString - 1)
			{
				return false;
			}
		}
	}
	return true;
}
bool MyString::operator!= (const char* other)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	size_t lengthOtherString = 0;
	if (other != nullptr)
	{
		lengthOtherString = strlen(other);
	}
	if (lengthString == lengthOtherString)
	{
		for (int i = 0; i < lengthString; i++)
		{
			if (this->string_[i] == other[i])
			{
				continue;
			}
			else
			{
				break;
			}
			if (i == lengthString - 1)
			{
				return false;
			}
		}
	}
	return true;
}
bool MyString::operator!= (const char symbol)
{
	size_t lengthString = 0;
	if (this->string_ != nullptr)
	{
		lengthString = strlen(this->string_);
	}
	if (lengthString == 1)
	{
		if (this->string_[0] == symbol)
		{
			return true;
		}
	}
	return false;
}
char& MyString::operator[] (const int index)
{
	if (index >= this->length())
	{
		throw "Error! Get out of range of array!";
	}
	return this->string_[index];
}

std::ostream& operator<< (std::ostream& outStream, const MyString& outString)
{
	outStream << outString.string_;
	return outStream;
}
std::istream& operator>> (std::istream& inStream, MyString& inString)
{
	MyString temp;
	while (true)
	{
		char symbol;
		symbol = inStream.get();
		if (symbol == ' ' || symbol == '\n' || symbol == '\t')
		{
			break;
		}
		if (symbol == EOF)
		{
			throw "Error! Stream interrupted!";
		}
		temp += symbol;
	}
	inString = temp;
	return inStream;
}

char* MyString::get() const
{
	return string_;
}
size_t MyString::length() const
	{
		size_t i = 0;
		while (string_[i] != '\0')
		{
			i++;
		}
		return i;
	}