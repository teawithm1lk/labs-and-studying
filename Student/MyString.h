#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* string);
	MyString(const MyString& object);
	~MyString();

	MyString& operator= (const MyString& otherString);
	MyString operator+ (const MyString& otherString);
	MyString operator+ (const char* other);
	MyString operator+ (const char symbol);
	MyString& operator+= (const MyString& otherString);
	MyString& operator+= (const char* other);
	MyString& operator+= (const char symbol);
	bool operator== (const MyString& otherObject);
	bool operator== (const char* other);
	bool operator== (const char symbol);
	bool operator!= (const MyString& otherString);
	bool operator!= (const char* other);
	bool operator!= (const char symbol);
	char& operator[] (const int index);

	friend std::ostream& operator<< (std::ostream& outStream, const MyString& outString);
	friend std::istream& operator>> (std::istream& inStream, MyString& inString);

	char* get() const;
	size_t length() const ;
private:
	char* string_;
};

#endif 