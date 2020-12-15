#ifndef MAINFUNCTIONS_H
#define MAINFUNCTIONS_H

#include <fstream>
#include <iomanip>
#include "Dynamic.h"
#include "Student.h"
#include "Sort.h"

size_t findBest(Dynamic<Student>& arrayOfStudents);

void outputSortedArray(Dynamic<Student>&students);

#endif