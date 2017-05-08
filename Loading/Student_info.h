#pragma once
#ifndef __STUDENT_INFO_H_
#define __STUDENT_INFO_H_

#include"titles_check_functions.h"
#include<string>

typedef class Student_info* student_link;
typedef struct list* Position;

class Student_info
{
public:
	Student_info(const std::string &IDcode) :ID(IDcode), score(0) {}
	Student_info() :score(0) {}
	Student_info(std::istream &is) { is >> *this; }
	friend std::istream& operator >> (std::istream &, Student_info &);
	friend std::ostream& operator << (std::ostream &, const Student_info &);

	std::string ID;
	int score;
};
inline std::istream& operator >> (std::istream &in, Student_info &s)
{
	in >> s.ID >> s.score;
	return in;
}
inline std::ostream& operator<<(std::ostream &out,const Student_info &s)
{
	out << s.ID << "\t" << s.score << "\t" << std::endl;
	return out;
}
struct list
{
	Student_info student;
	Position Next;
};

#endif // !__STUDENT_INFO_H_
