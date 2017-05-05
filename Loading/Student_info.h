#pragma once
#ifndef __STUDENT_INFO_H_
#define __STUDENT_INFO_H_

#include"titles_check_functions.h"

typedef struct Student_info* student_link;
typedef struct list* Position;

struct Student_info {
	std::string student_num;
	int score;
};

struct list
{
	Student_info student;
	Position Next;
};

#endif // !__STUDENT_INFO_H_
