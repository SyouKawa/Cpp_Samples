#pragma once
#ifndef __STUDENT_INFO_H_
#define __STUDENT_INFO_H_

#include"titles_check_functions.h"
#include<string>
#include<fstream>

typedef class Student_info* student_link;
typedef struct list* Position;

class Student_info
{
public:
	Student_info(const std::string &IDcode, const std::string &scores) :ID(IDcode), s_score(scores),score(0) {}
	Student_info() {}
	Student_info(std::istream &is) { is >> *this; }
	friend std::istream& operator >> (std::istream &, Student_info &);
	friend std::ostream& operator << (std::ostream &, const Student_info &);
	friend int string2int(const std::string&source);

	std::string ID;
	std::string s_score;
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

/*inline int string2int(std::string& source) {
	char a = '0';
	int temp(0);
	int pow_size = source.size() - 1;
	for (int i(0); i<source.size(); i++) {
		a = source[i];
		int level = pow(10, pow_size);
		temp += level * int(a - 48);// ASCII:1~9:start from 49.
		pow_size--;
	}
	return temp;
}*/

struct list
{
	Student_info student;
	Position Next;
};

#endif // !__STUDENT_INFO_H_
