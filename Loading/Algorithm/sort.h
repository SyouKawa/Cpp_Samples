#pragma once
#ifndef __SORT_H_
#define __SORT_H_

#include "titles_check_functions.h"
#include"Student_info.h"

Student_info& Median3(std::vector<Student_info>&students, int Left, int Right);
void Qsort(std::vector<Student_info>&student, int Left, int Right);
void Qsort2(std::vector<Student_info>& student, int Left, int Right);
void Insertion(std::vector<Student_info>&student);
void Bubble(std::vector<Student_info>&student);
void Select(std::vector<Student_info>&student);
void Merge_sort(std::vector<Student_info>&student, std::vector<Student_info>&temp,int Left, int Right);
void Merge_part(std::vector<Student_info>&student, std::vector<Student_info>&temp, int Left, int Right);
#endif // !__SORT_H_
