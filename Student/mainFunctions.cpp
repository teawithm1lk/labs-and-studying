#include "mainFunctions.h"

size_t findBest(Dynamic<Student>& arrayOfStudents)
{
  Student bestStudent;
  size_t indexBestStudent = 0;
  size_t length = arrayOfStudents.getSize();
  for (size_t i = 0; i < length; ++i)
  {
    if (arrayOfStudents[i] >= bestStudent)
    {
      bestStudent = arrayOfStudents[i];
      indexBestStudent = i;
    }
  }
  return indexBestStudent;
}

void outputSortedArray(Dynamic<Student>& students)
{
  size_t bestStudent = 0;
  bestStudent = findBest(students) + 1;
  std::cout << "The best student is number " << bestStudent;
  size_t lengthStudents = students.getSize();
  sort(students, lengthStudents);
  std::ofstream out;
  out.open("output.txt");
  if (!out.is_open())
  {
    throw "File is not found! Please, create something.";
  }
  MyString nameHeader = "Student's Name";
  MyString specialtyHeader = "Student's Specialty";
  MyString groupHeader = "Student's Group";
  MyString semesterHeader = "Semester of Studying";
  MyString marksHeader = "Student's Marks";
  size_t nameHeaderLength = nameHeader.length();
  size_t specialtyHeaderLength = specialtyHeader.length();
  size_t groupHeaderLength = groupHeader.length();
  size_t semesterHeaderLength = semesterHeader.length();
  size_t marksHeaderLength = marksHeader.length();
  size_t maxNameColumnLength = 0;
  size_t maxSpecialtyColumnLength = 0;
  size_t maxMarksColumnLength = 0;
  for (size_t i = 0; i < lengthStudents; ++i)
  {
    maxNameColumnLength = (students[i].getNameLength() > maxNameColumnLength) ? students[i].getNameLength() : maxNameColumnLength;
    maxSpecialtyColumnLength = (students[i].getSpecialtyLength() > maxSpecialtyColumnLength) ? students[i].getSpecialtyLength() : maxSpecialtyColumnLength;
    maxMarksColumnLength = (students[i].getMarksLength() > maxMarksColumnLength) ? students[i].getMarksLength() : maxMarksColumnLength;
  }
  maxNameColumnLength = (nameHeaderLength > maxNameColumnLength) ? nameHeaderLength : maxNameColumnLength;
  maxSpecialtyColumnLength = (specialtyHeaderLength > maxSpecialtyColumnLength) ? specialtyHeaderLength : maxSpecialtyColumnLength;
  maxMarksColumnLength = (marksHeaderLength > maxMarksColumnLength) ? marksHeaderLength : maxMarksColumnLength;
  size_t linesLength = 16 + maxMarksColumnLength + maxNameColumnLength + maxSpecialtyColumnLength + groupHeaderLength + semesterHeaderLength;
  for (size_t i = 0; i < linesLength; ++i)
  {
    out << '-';
  }
  out << '\n';
  size_t setwName = maxNameColumnLength + 1;
  size_t setwSpecialty = maxSpecialtyColumnLength + 1;
  size_t setwGroup = groupHeaderLength + 1;
  size_t setwSemester = semesterHeaderLength + 1;
  size_t setwMarks = maxMarksColumnLength + 1;
  out << '|' << std::setw(setwName) << nameHeader << std::setw(2) << '|' << std::setw(setwSpecialty) << specialtyHeader << std::setw(2) << '|'
    << std::setw(setwGroup) << groupHeader << std::setw(2) << '|' << std::setw(setwSemester) << semesterHeader << std::setw(2) << '|'
    << std::setw(setwMarks) << marksHeader << std::setw(2) << '|' << '\n';
  for (size_t i = 0; i < linesLength; ++i)
  {
    out << '-';
  }
  for (size_t i = 0; i < lengthStudents; ++i)
  {
    setwMarks = maxMarksColumnLength - students[i].getMarksLength() + 2;
    out << '\n';
    students[i].outputToTable(out, setwName, setwSpecialty, setwGroup, setwSemester, setwMarks);
  }
  out << '\n';
  for (size_t i = 0; i < linesLength; ++i)
  {
    out << '-';
  }
}
