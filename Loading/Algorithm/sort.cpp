#include"titles_check_functions.h"
#include"sort.h"
using namespace std;

void swap(Student_info* a, Student_info* b) {
	Student_info student_temp;
	student_temp = *a;
	*a = *b;
	*b = student_temp;
}

Student_info& Median3(vector<Student_info>& students, int Left, int Right) {
	int Center = (Left + Right) / 2;
	if (students[Left].score > students[Center].score)swap(students[Left], students[Center]);
	if (students[Center].score > students[Right - 1].score)swap(students[Right - 1], students[Center]);
	if (students[Left].score > students[Right - 1].score)swap(students[Left], students[Right - 1]);
	swap(students[Center], students[Right - 2]);
	//int pivot = string2int(students[Right - 2].score);
	return students[Right - 2];
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
void Qsort2(vector<Student_info>& student,int Left, int Right) {
	if (Left > Right) { return; }

	int i=Left, j=Right-1;
	Student_info Pivot=Median3(student,Left,Right);
	
	while(i < j) {
		while (i < Right && student[i].score < Pivot.score) { i++;}
		while (i < Right && student[j].score > Pivot.score) { j--;}
			if (i < j)swap(student[i], student[j]);
			else break;
	}
	swap(student[i],Pivot);
	Qsort(student, Left, i);
	Qsort(student, i+1, Right);
}

void Insertion(vector<Student_info>&student) {
	for (int j(1); j < student.size(); j++) {
		Student_info temp = student[j];
		int i = j-1;
		for (;i>=0&&student[i].score>temp.score;i--) student[i+1] = student[i];
		student[i+1] = temp;
	}
}

void Bubble(vector<Student_info>&student) {
	for (int i(0);i<student.size();i++) {
		for (int j(i+1); j < student.size(); j++)
			if (student[i].score > student[j].score) swap(student[i], student[j]);
	}
}

void Select(vector<Student_info>&student) {
	Student_info min = student[0];
	int min_flag(0);
	for (int roll(0);roll<student.size();roll++) {
		min = student[roll];
		for (int i(roll); i < student.size(); i++) 
			if (min.score > student[i].score) {
				min_flag = i;
				min = student[i];
			} 
		swap(student[roll], student[min_flag]);
	}
}

void Merge_part(vector<Student_info>&student,vector<Student_info>&temp,int Left,int Right) {
	if (Left < Right) {
		int middle = (Right - Left) / 2;
		Merge_part(student, temp,Left, middle);
		Merge_part(student, temp,middle + 1, Right);
		Merge_sort(student, temp, Left, Right);

	}
	
}

void Merge_sort(vector<Student_info>&student,vector<Student_info>&temp,int Left,int Right) {
	int Center = (Right - Left) / 2;
	for (int i(Left), j(Center+1); i <= Center || j <= Right;) {
		if (student[i].score <= student[j].score) { temp.push_back(student[i]); if(i < Center)i++; }
		if (i < Center && j == Right) { temp.push_back(student[i]); i++; }
		if (i == Center && j < Right) { temp.push_back(student[j]); j++; }
		if (student[i].score >  student[j].score) { temp.push_back(student[j]); if(j < Right )j++; }
	}
}