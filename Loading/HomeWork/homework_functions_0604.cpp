#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"homework_functions_0604.h"

using namespace std;

void multi_result() {
	int multi_result(0);
	for (int num(1); num < 10; num++) {//num:��ʾ���е������������о�������ٸ���������ڼ��о�����������������
		for (int line(1); line <= num; line++) {//line:��ʾ���еı���������1��������num��
			multi_result = num*line;
			printf("%dX%d=%d  ", line, num, multi_result);
		}
		cout << endl;
	}
}

void print_diamond_Basic() {
	int num = 0;// middle line sum

	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines
	int simple_line_sum = num - lines; //eg:7-3=4->the first line's sum
									   //int space_count = num - simple_line_sum; //eg:3 spaces + 4 lines_sum=7
									   //int star_count = simple_line_sum - space_count;

	printf("\nOK,you need %d up-lines,and %d down-lines.\n\n", lines, lines);
	cout << "And like this:" << endl;

	for (int i = 0; i < lines; ++i) {
		for (int j = num - simple_line_sum; j != 0; --j) printf(" ");
		for (int j = simple_line_sum - (num - simple_line_sum); j != 0; --j)printf("*");
		simple_line_sum++;
		printf("\n");
		//printf("%d", simple_line_sum);
	}

	for (int i = 0; i < num; ++i) printf("*");
	printf("\n");

	for (int i = 1; i <= lines; ++i) {
		for (int j = 0; j<i; ++j) printf(" ");
		for (int j = 0; j<simple_line_sum - (2 * i); ++j)printf("*");
		printf("\n");
	}
	system("pause");
}

void print_diamond_1() {
	int num = 0;// middle line sum

	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines
	int simple_line_sum = num - lines; //eg:7-3=4->the first line's sum
									   //int space_count = num - simple_line_sum; //eg:3 spaces + 4 lines_sum=7
									   //int star_count = simple_line_sum - space_count;

	printf("\nOK,you need %d up-lines,and %d down-lines.\n\n", lines, lines);
	cout << "And like this:" << endl;

	for (int i = 0; i <= lines; ++i) {
		for (int j = num - simple_line_sum; j != 0; --j) printf(" ");

		for (int j = simple_line_sum - (num - simple_line_sum); j != 0; --j) {
			if(j%2==0)printf("*");
			else printf(" ");
		}
		simple_line_sum++;
		printf("\n");
		//printf("%d", simple_line_sum);
	}

	for (int i = 0; i < num; ++i) {
		if (i % 2 == 0)printf("*");
		else printf(" ");
	}
	printf("\n");

	for (int i = 1; i <= lines; ++i) {
		for (int j = 0; j<i; ++j) printf(" ");
		for (int j = 0; j < simple_line_sum - (2 * i); ++j) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	system("pause");
}

void print_diamond_2() {
	int num = 0;// middle line sum
	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines_sum
	
	//  I �� II ����
	int x = 0 - lines;
	int y = lines;
	int position = lines;

	for (;y>=0;y--) {
		for (x=0-lines;x<0;x++) {//�ڶ�����
			if (x - y == 0-position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//��һ����
			if (x + y == position) printf("*");
			else printf(" ");
		}
		cout << endl;
	}

	//  III �� IV ����
	for (; y <= 0; y--) {
		for (x = 0 - lines; x<0; x++) {//��������
			if ((x+y) == 0 - position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//��������
			if ((y-x) == 0- position) printf("*");
			else printf(" ");
		}
		cout << endl;
		if (0 - y == num - 1) break;
	}
}
