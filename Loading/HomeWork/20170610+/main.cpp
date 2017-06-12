#include<stdio.h>
#include<iostream>
//#include"homework_functions_0604.h"
//#include"homework_functions_0606.h"
//#include"homework_functions_0607.h"
//#include"homework_functions_0608.h"
//#include"homework_functions_0609.h"
#include"homework_functions_loading.h"
using namespace std;


void main() {
	int count = 0;
	printf("Please input the number of Students you wanna save: ");
	scanf("%d", &count);
	Students *student_list = NULL;
	FILE *input = fopen("Student_info.txt","r");
	
	for (int i=count;i!=0;i--) {
		add_element(&student_list, input);
	}
	fclose(input);
	print_students_data(student_list);

	//Blues.input_int();
	//.output();

	getchar();
	getchar();
}