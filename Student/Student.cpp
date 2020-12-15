#include "Student.h"

Student::Student()
{
	group_ = 0;
	semester_ = 0;
	marks_ = new size_t[WIDTH];
	for (size_t i = 0; i < WIDTH; i++)
	{
		marks_[i] = 0;
	}
}
Student::Student(const MyString name, const MyString specialty, const size_t group, const size_t semester, const size_t* marks)
{
	name_ = name;
	specialty_ = specialty;
	group_ = group;
	semester_ = semester;
	marks_ = new size_t[WIDTH];
	for (size_t i = 0; i < WIDTH; i++)
	{
		marks_[i] = marks[i];
	}
}
Student::Student(const MyString name, const MyString specialty, const size_t group, const size_t semester, const size_t marks0, const size_t marks1, const size_t marks2, const size_t marks3, const size_t marks4)
{
	name_ = name;
	specialty_ = specialty;
	group_ = group;
	semester_ = semester;
	marks_ = new size_t[WIDTH];
	marks_[0] = marks0;
	marks_[1] = marks1;
	marks_[2] = marks2;
	marks_[3] = marks3;
	marks_[4] = marks4;
}
Student::Student(const Student& object)
{
	this->name_ = object.name_;
	this->specialty_ = object.specialty_;
	this->group_ = object.group_;
	this->semester_ = object.semester_;
	this->marks_ = new size_t[WIDTH];
	for (size_t i = 0; i < WIDTH; i++)
	{
		this->marks_[i] = object.marks_[i];
	}
}
Student::~Student()
{
	delete[]marks_;
}

Student& Student::operator++ ()
{
	for (size_t i = 0; i < WIDTH; i++)
	{
		this->marks_[i]++;
	}
	return *this;
}
Student& Student::operator= (Student& object)
{
	this->name_ = object.name_;
	this->specialty_ = object.specialty_;
	this->group_ = object.group_;
	this->semester_ = object.semester_;
	for (size_t i = 0; i < WIDTH; i++)
	{
		this->marks_[i] = object.marks_[i];
	}
	return *this;
}
bool Student::operator>= (const Student& object)
{
	size_t sum1 = 0;
	size_t sum2 = 0;
	for (size_t i = 0; i < WIDTH; i++)
	{
		sum1 += this->marks_[i];
		sum2 += object.marks_[i];
	}
	if (sum1 >= sum2)
	{
		return true;
	}
	return false;
}
bool Student::operator> (const Student& object)
{
	size_t sum1 = 0;
	size_t sum2 = 0;
	for (size_t i = 0; i < WIDTH; i++)
	{
		sum1 += this->marks_[i];
		sum2 += object.marks_[i];
	}
	if (sum1 > sum2)
	{
		return true;
	}
	return false;
}

Student& operator++ (Student& object, int) 
{
	Student temp(object);
	for (size_t i = 0; i < object.WIDTH; i++)
	{
		object.marks_[i]++;
	}
	return temp;
}
bool operator== (Student& object1, Student& object2)
{
	size_t sum1 = 0;
	size_t sum2 = 0;
	for (size_t i = 0; i < object1.WIDTH; i++)
	{
		sum1 += object1.marks_[i];
		sum2 += object2.marks_[i];
	}
	return (object1.specialty_ == object2.specialty_) && (object1.semester_ == object2.semester_) && (sum1 == sum2);
}
Student operator+ (Student& object, int number)
{
	for (size_t i = 0; i < object.WIDTH; i++)
	{
		object.marks_[i] += number;
	}
	return object;
}
std::ostream& operator<< (std::ostream& outStream, const Student& studentOut)
{
	outStream << studentOut.name_ << '\n' << studentOut.specialty_ << '\n' << studentOut.group_ << '\n' << studentOut.semester_ << '\n';
	for (size_t i = 0; i < studentOut.WIDTH; i++)
	{
		outStream << studentOut.marks_[i] << ' ';
	}
	return outStream;
}
std::istream& operator>> (std::istream& inStream, Student& studentIn)
{
	if (inStream.get() == EOF)
	{
		throw "Error! Stream interrupted!";
	}
	inStream.unget();
	inStream >> studentIn.name_;
	if (studentIn.name_[1] != '.' or studentIn.name_[3] != '.')
	{
		throw "Incorrectly wroten parameter name!";
	}
	if (inStream.get() == EOF)
	{
		throw "Error! Stream interrupted!";
	}
	inStream.unget();
	inStream >> studentIn.specialty_;
	if (inStream.get() == EOF)
	{
		throw "Error! Stream interrupted!";
	}
	inStream.unget();
	inStream >> studentIn.group_;
	if (studentIn.group_ < 0)
	{
		throw "Incorrectly wroten parameter group!";
	}
	if (inStream.get() == EOF)
	{
		throw "Error! Stream interrupted!";
	}
	inStream.unget();
	inStream >> studentIn.semester_;
	if (studentIn.semester_ < 0 || studentIn.semester_ > 14)
	{
		throw "Incorrectly wroten parameter semester!";
	}
	for (size_t i = 0; i < studentIn.WIDTH; i++)
	{
		if ((i != studentIn.WIDTH - 1) && (inStream.get() == EOF))
		{
			throw "Error! Stream interrupted!";
		}
		inStream >> studentIn.marks_[i];
		if (studentIn.marks_[i] < 0 || studentIn.marks_[i] > 9)
		{
			throw "Incorrectly wroten parameter mark!";
		}
	}
	return inStream;
}

size_t Student::getNameLength()
{
	return this->name_.length();
}
size_t Student::getSpecialtyLength()
{
	return this->specialty_.length();
}
size_t Student::getMarksLength()
{
	size_t length = 0;
	for (size_t i = 0; i < WIDTH; ++i)
	{
		size_t temp = marks_[i];
		while (temp/10 != 0)
		{
			++length;
			temp /= 10;
		}
		length += 2;
	}
	--length;
	return length;
}
MyString Student::getName()
{
	return this->name_;
}
MyString Student::getSpecialty()
{
	return this->specialty_;
}
size_t Student::getGroup()
{
	return this->group_;
}
size_t Student::getSemester()
{
	return this->semester_;
}
size_t* Student::getMarks()
{
	return this->marks_;
}
void Student::outputToTable(std::ofstream& out, size_t setwName, size_t setwSpecialty, size_t setwGroup, size_t setwSemester, size_t setwMarks)
{
	out << '|' << std::setw(setwName) << name_ << std::setw(2) << '|' << std::setw(setwSpecialty) << specialty_ << std::setw(2) << '|'
			<< std::setw(setwGroup) << group_ << std::setw(2) << '|' << std::setw(setwSemester) << semester_ << std::setw(2) << '|' << std::setw(setwMarks);
	for (size_t i = 0; i < WIDTH; i++)
	{
		out << marks_[i];
		if (i != (WIDTH - 1))
		{
			out << ' ';
		}
	}
	out << std::setw(2) << '|';
}
void Student::setName(MyString name)
{
	this->name_ = name;
}
void Student::setSpecialty(MyString specialty)
{
	this->specialty_ = specialty;
}
void Student::setGroup(size_t group)
{
	this->group_ = group;
}
void Student::setSemester(size_t semester)
{
	this->semester_ = semester;
}
void Student::setMarks(size_t* marks)
{
	*marks_ = *marks;
}
void Student::setMarks(size_t marks0, size_t marks1, size_t marks2, size_t marks3, size_t marks4)
{
	marks_[0] = marks0;
	marks_[1] = marks1;
	marks_[2] = marks2;
	marks_[3] = marks3;
	marks_[4] = marks4;
}