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

void swap(Student_info* a, Student_info* b) {
	Student_info student_temp;
	student_temp = *a;
	*a = *b;
	*b = student_temp;
}

void Qsort(vector<Student_info>&student, int Left, int Right) {
	if (Right > Left) {
		// partition
		int p = rand() % (Right - Left) + Left;
		Student_info d = student[p];
		// divide
		swap(student[Left], student[p]);
		int i = Left;
		int j = i + 1;
		while (j < Right) {
			while (student[j].score > d.score && j < Right) j++;
			if (j < Right) {
				i++;
				swap(student[i], student[j]);
				j++;
			}
		}
		swap(student[i], student[Left]);
		Qsort(student, Left, i);
		Qsort(student, i + 1, Right);
	}
	if (student[student.size()-2].score > student[student.size()-1].score) swap(student[student.size()-2], student[student.size() - 1]);
}

//#define Cutoff 3
/*void Qsort(vector<Student_info>& student,int Left, int Right) {
	if (Left >= Right) { return; }

	int i=Left, j=Right;
	int Pivot=student[i].score;
	
	while(i < j) {
			while (i<Right &&student[i++].score <= Pivot) {}
			while (i<Right &&student[j--].score >= Pivot) {}
			if (i <= j)swap(student[i], student[j]);
			else break;
	}
	student[i].score = Pivot;
	Qsort(student, Left, i - 1);
	Qsort(student, i+1, Right);
}*/