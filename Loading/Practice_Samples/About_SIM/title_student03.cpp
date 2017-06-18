#include"titles_check_functions.h"
#include"Student_info.h"
using namespace std;

void title_student03() {
	int size(0);
	list *student_list = new list[size];
	ifstream infile("Student Data.txt");
	ofstream outfile("Student List.txt", ofstream::app);
	string c;
	while (getline(infile, c))size++;
	cout<<infile.is_open();
	for (int i(0); i<size&&outfile.is_open(); i++) {
		infile >> (student_list + i)->student.ID >> (student_list + i)->student.score;
		outfile << (student_list + i)->student.ID << " : " << (student_list+i)->student.score << endl;
		if (i<size - 1) (student_list + i)->Next = student_list + i + 1;
		else (student_list + i)->Next = NULL;
	}
	outfile.close();
	infile.close();
}