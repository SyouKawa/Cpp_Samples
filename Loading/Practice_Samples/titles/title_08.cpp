#include<iostream>
#include<stdio.h>
using namespace std;

void main() {
	int num[] = { 1,2,3,4,5,6,7,8,9 };

	for(int i=0;i<(sizeof(num)/sizeof(int));++i)
		for (int j = 0; j < (sizeof(num) / sizeof(int)); ++j) {
			printf("%dX%d=%d ", num[i], num[j], num[i] * num[j]);
			//cout << num[i] << "X" << num[j] << "=" << num[i] * num[j];
			if (i == j) { puts("\n"); break; }
}

	system("pause");
}