#include <iostream>
#include <stdio.h>
using namespace std;

void sum_function(int num,double sum) {
	int up_former = 2;//change later
	int down_former = 1;//change later
	//int up_later = up_former + down_former;
	sum = up_former/down_former;
	for (int i = 1; i <= num; i++) {
		int down_later = up_former;
		sum += ((up_former+down_former) / down_later);
		printf("%d/%d", up_former + down_former, down_later);
		//cout << up_former + down_former << "/" << down_later;
		if (i != num) printf("+");
		if (i == num) printf("=");
		up_former = up_former + down_former;
		down_former = down_later;
	}
	printf("%3lf", sum);
}

void main() {
	int num = 0;
	double sum = 0;
	printf("Please input the number of items you want: ");
	cin >> num;
	cout << endl;
	sum_function(num, sum);
	printf("\n\nThanks for using.:-)");
	system("pause");
}