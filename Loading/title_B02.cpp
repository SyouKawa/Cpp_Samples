#include"titles_check_functions.h"
#include"Student_info.h"
#include<string>
using namespace std;

void title_B34(){
	printf("Please input the size of list you wanna: ");
	int size(0);
	cin >> size;
	list *student_list=(list*)malloc(size * sizeof(list));
	int i = 0;
	printf("student_list  : %d\n", sizeof(student_list));
	printf("int : %d\n", sizeof(int));
	printf("student_list->Next : %d\n", sizeof(student_list->Next));
	printf("student_list->student : %d\n", sizeof(student_list->student));
	printf("student_list->student.student_num : %d\n", sizeof(student_list->student.student_num));//不是内存不够的问题。
	printf("20170124320: %d\n", sizeof("20170124320"));
	printf("string : %d\n", sizeof(string));
	
	Student_info test;
	Student_info * ptr;
	list student1;
	list * s;
	s = &student1;//list * 需要一个list 实体。
	s->student.student_num = "20170124320";
	ptr = &test;
	//test.student_num = "20170124320";
	//ptr->student_num = "20170124320";
	cout << student1.student.student_num;
	 	
	
	//for (int i(0);i<size;i++) {
	//list *student_list = (list*)malloc(size * sizeof(list));
	(*(student_list + i)).student.score = 100;
	(*(student_list + i)).Next = NULL;
	student_list->student.student_num="20170124320";//init problem
	//}
	//string a();
	for(size_t i(0);i<sizeof((*student_list).student.student_num);i++)
		printf("%c",(*student_list).student.student_num);
	printf(" : %d \n", (*student_list).student.score);
}