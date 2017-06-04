#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"homework_functions_0604.h"

using namespace std;

void multi_result() {
	int multi_result(0);
	for (int num(1); num < 10; num++) {//num:表示该行的主乘数，该行就输出多少个结果。（第几行就输出几个乘数结果）
		for (int line(1); line <= num; line++) {//line:表示该行的被乘数，从1到主乘数num。
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
	
	//  I 和 II 象限
	int x = 0 - lines;
	int y = lines;
	int position = lines;

	for (;y>=0;y--) {
		for (x=0-lines;x<0;x++) {//第二象限
			if (x - y == 0-position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//第一象限
			if (x + y == position) printf("*");
			else printf(" ");
		}
		cout << endl;
	}

	//  III 和 IV 象限
	for (; y <= 0; y--) {
		for (x = 0 - lines; x<0; x++) {//第三象限
			if ((x+y) == 0 - position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//第四象限
			if ((y-x) == 0- position) printf("*");
			else printf(" ");
		}
		cout << endl;
		if (0 - y == num - 1) break;
	}
}

void print_diamond_3() {
	int middle(0);
	printf("Please input the length of middle you want:");
	cin >> middle;
	//part-1
	int trangle_bottom = ((middle + 1) / 2)+1;
	int bottom_flower = trangle_bottom / 2;
	for (int line(bottom_flower),space(bottom_flower); line != 0; line--, space--) {
		for (int i(space); i != 0; i--) printf(" ");

		//middle part
		for (int flower(trangle_bottom-2*space);flower!=0;flower--) {
			if (flower % 2 == 0) printf(" ");
			else printf("*");
		}

		printf(" ");

		for (int j(space); j != 0; j--) printf(" ");

		//double:
		for (int i(space); i != 0; i--) printf(" ");

		//middle part
		for (int flower(trangle_bottom - 2 * space); flower != 0; flower--) {
			if (flower % 2 == 0) printf(" ");
			else printf("*");
		}

		printf(" ");

		for (int j(space); j != 0; j--) printf(" ");

		cout << endl;
	}

	//part-2
	for (int line(middle+3),line_num(0); line >= (middle+3+1) / 2; line--,line_num++) {
		for (int i(line_num); i != 0; i--)printf(" ");
		for (int this_line(line-line_num); this_line > 0; this_line--) {
			if (this_line % 2 == 0)printf(" ");
			else printf("*");
		}
		cout << endl;
	}
}