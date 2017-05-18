#include"titles_check_functions.h"
#include"Student_info.h"
#include"sort.h"
#include<unordered_map>
using namespace std;

Student_info split_input(string& c, Student_info& student);
//void scores_list(vector<Student_info>& students, vector<int>&scores);
int string2int(string&source);
//int& Median3(vector<Student_info>& students, int Left, int Right);
//void swap(Student_info* a, Student_info* b);

void title_student04() {
	vector<Student_info> student_list;
	ifstream infile("Student Data.txt");
	string c;
	Student_info temp;

	while (getline(infile, c))
		student_list.push_back(split_input(c, temp));
	infile.close();

	for (vector<Student_info>::iterator iter = student_list.begin(); iter != student_list.end(); iter++) {
		cout << iter->ID << " : " << iter->s_score << endl;
	}

	vector<int>scores(0);
	//scores_list(student_list, scores);
	cout << Median3(student_list, 0, student_list.size()) << endl;
	Qsort(student_list, 0,student_list.size()-1);//student_list.size()-1);

	for (vector<Student_info>::iterator iter = student_list.begin(); iter != student_list.end(); iter++) {
		cout << iter->ID << " : " << iter->s_score << endl;
	}
}

/*void RadixSort(vector<Student_info>&student) {
	unordered_map<int, vector<Student_info> > test_map;

}*/

Student_info split_input(string& c, Student_info& student) {
	string::size_type i(0);
	int flag(0);
	while (i != c.size()) {
		for (; i != c.size() && isspace(c[i]); ++i);
		string::size_type j = i;
		for (; j != c.size() && !isspace(c[j]); ++j);
		if (i != j&&flag == 0) student.ID = c.substr(i, j - i);
		if (i != j&&flag == 1) student.s_score = c.substr(i, j - i);
		student.score = string2int(student.s_score);
		flag++;
		i = j;
	}
	return student;
}
/*void scores_list(vector<Student_info>& students, vector<int>&scores) {
	for (vector<Student_info>::iterator iter=students.begin();iter!=students.end();++iter)
		scores.push_back(string2int(iter->score));
}*/

int string2int(string&source) {
	char a = '0';
	int temp(0);
	int pow_size = source.size()-1;
	for (int i(0);i<source.size();i++) {
		a = source[i];
		int level = pow(10,pow_size);
		temp += level * int(a-48);// ASCII:1~9:start from 49.
		pow_size--;
	}
	return temp;
}

/*void swap(Student_info* a, Student_info* b) {
	Student_info student_temp;
	student_temp = *a;
	*a = *b;
	*b = student_temp;
}*/