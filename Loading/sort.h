#pragma once
#ifndef __SORT_H_
#define __SORT_H_

#include "titles_check_functions.h"
#include"Student_info.h"

int& Median3(std::vector<Student_info>&students, int Left, int Right);
void Qsort(std::vector<Student_info>&student, int Left, int Right);

#endif // !__SORT_H_
