#include"titles_check_functions.h"
#include"sort.h"
using namespace std;

int& Median3(vector<Student_info>& students, int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (students[Left].score > students[Center].score)swap(students[Left], students[Center]);
	if (students[Center].score > students[Right - 1].score)swap(students[Right - 1], students[Center]);
	if (students[Left].score > students[Right - 1].score)swap(students[Left], students[Right - 1]);
	swap(students[Center], students[Right - 2]);
	//int pivot = string2int(students[Right - 2].score);
	return students[Right - 2].score;
}

#define Cutoff 3
void Qsort(vector<Student_info>& student,int Left, int Right) {
	int i(0), j(0);
	int Pivot;
	if (Left + Cutoff <= Right) {
		Pivot = Median3(student, Left, Right);
		i = Left;
		j = Right - 1;
		for (;;) {
			while (student[++i].score < Pivot) {}
			while (student[--j].score > Pivot) {}
			if (i < j) swap(student[i], student[j]);
			else break;
		}
		swap(student[i], student[Right - 1]);
		//left-part resort
		Qsort(student, Left, i - 1);
		//right-part resort
		Qsort(student, i, Right);
	}
	//else
}