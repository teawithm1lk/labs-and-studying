#ifndef STUDENT_H
#define STUDENT_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include "MyString.h"

class Student
{
public:
	Student();
	Student(const MyString name, const MyString specialty, const size_t group, const size_t semester, const size_t* marks);
	Student(const MyString name, const MyString specialty, const size_t group, const size_t semester, const size_t marks0, const size_t marks1, const size_t marks2, const size_t marks3, const size_t marks4);
	Student(const Student& object);
	~Student();

	Student& operator++ ();
	Student& operator= (Student& object);
	bool operator>= (const Student& object);
	bool operator> (const Student& object);

	friend Student& operator++ (Student& object, int);
	friend bool operator== (Student& object1, Student& object2);
	friend Student operator+ (Student& object, int number);
	friend std::ostream& operator<< (std::ostream& outStream, const Student& studentOut);
	friend std::istream& operator>> (std::istream& inStream, Student& studentIn);

	size_t getNameLength();
	size_t getSpecialtyLength();
	size_t getMarksLength();
	MyString getName();
	MyString getSpecialty();
	size_t getGroup();
	size_t getSemester();
	size_t* getMarks();
	void outputToTable(std::ofstream& out, size_t setwName, size_t setwSpecialty, size_t setwGroup, size_t setwSemester, size_t setwMarks);
	void setName(MyString name);
	void setSpecialty(MyString specialty);
	void setGroup(size_t group);
	void setSemester(size_t semester);
	void setMarks(size_t* marks);
	void setMarks(size_t marks0, size_t marks1, size_t marks2, size_t marks3, size_t marks4);
private:
	const int WIDTH = 5;
	MyString name_;
	MyString specialty_;
	size_t group_;
	size_t semester_;
	size_t* marks_;
};

#endif