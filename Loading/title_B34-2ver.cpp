#include"titles_check_functions.h"
#include"Student_info.h"
#include<string>
#include<fstream>
using namespace std;

void title_B34(){
	printf("Please input the size of list you wanna: ");
	int size(0);
	cin >> size;
	//list *student_list=(list*)malloc(size * sizeof(list));
	list *student_list = new list[size];

	ofstream wfile("Student List.txt",ofstream::app);

	for (int i(0);i<size&&wfile.is_open();i++) {
	printf("Please input student\'s IDcode and his\\her score behind with a space: ");
	cin >> (student_list + i)->student.ID >> (student_list + i)->student.score;
	wfile << (student_list + i)->student.ID << " : " << (student_list)->student.score << endl;
	if(i<size-1) (student_list+i)->Next = student_list+i+1;
	else (student_list + i)->Next = NULL;
	}
	wfile.close();
	/*/debug using 
	for(size_t i(0);i<size;i++)
		cout << (student_list+i)->student.ID << " : " << (student_list+i)->student.score << endl;*/
}