#include"titles_check_functions.h"
#include"Student_info.h"
using namespace std;

Student_info split_input(string& c, Student_info& student);

void title_student04() {
	vector<Student_info> student_list;
	ifstream infile("Student Data.txt");
	string c;
	Student_info temp;

	while (getline(infile, c))
		student_list.push_back(split_input(c, temp));
	infile.close();

	for (vector<Student_info>::iterator iter = student_list.begin(); iter != student_list.end(); iter++)
		cout << iter->ID << " : " << iter->score << endl;
}
Student_info split_input(string& c, Student_info& student) {
	string::size_type i(0);
	int flag(0);
	while (i != c.size()) {
		for (; i != c.size() && isspace(c[i]); ++i);
		string::size_type j = i;
		for (; j != c.size() && !isspace(c[j]); ++j);
		if (i != j&&flag == 0) student.ID = c.substr(i, j - i);
		if (i != j&&flag == 1) student.score = c.substr(i, j - i);
		flag++;
		i = j;
	}
	return student;
}