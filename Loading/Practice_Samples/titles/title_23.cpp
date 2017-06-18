#include <stdio.h>
#include <iostream>
using namespace std;
void main() {
	int num=0;// middle line sum
	
	cout<<"Please input the number of * you want :";
	cin >> num;
	
	int lines = num / 2; // up-lines
	int simple_line_sum = num - lines; //eg:7-3=4->the first line's sum
	//int space_count = num - simple_line_sum; //eg:3 spaces + 4 lines_sum=7
	//int star_count = simple_line_sum - space_count;

	printf("\nOK,you need %d up-lines,and %d down-lines.\n\n", lines, lines);
	cout << "And like this:" << endl;

	for (int i = 0; i < lines; ++i) {
			for (int j = num-simple_line_sum; j != 0; --j) printf(" ");
			for (int j = simple_line_sum-(num-simple_line_sum); j != 0; --j)printf("*");
			simple_line_sum++;
			printf("\n");
			//printf("%d", simple_line_sum);
	}

	for (int i = 0; i < num; ++i) printf("*");
	printf("\n");

	for (int i = 1; i <= lines; ++i) {
		for (int j=0;j<i;++j) printf(" ");
		for (int j=0;j<simple_line_sum-(i-1);++j)printf("*");
		simple_line_sum--;
		printf("\n");
	}
	system("pause");
}