#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void output_factorial_sum(int num,double&sum, int&factorial, vector<double>&each_factorial);
void check_factorial(const vector<double>& each_factorial);

void main() {
	double sum = 0;//outside +,inside *
	int factorial = 1;
	vector<double>each_factorial(0);

	printf("Hi~Please input the size of N in factorial sum you want:");
	int num(0);
	cin >> num;
	output_factorial_sum(num,sum,factorial,each_factorial);

	printf("Do you wanna check the result of factorial?(Y/N)");
	char status(0);
	cin >> status;
	if (status == 'Y') {
		for (bool flag = 1; flag == 1;) {
			check_factorial(each_factorial);
			printf("\n\nStill check? Or Quit? (1/0):");
			cin >> flag;
		}
	}
	cout << "Thanks for using.  : )";
	system("pause");
}

void output_factorial_sum(int num,double&sum,int&factorial,vector<double>&each_factorial) {
	int count = 0;
	for (int i = 1; i <= num; ++i) {
		for (int j = count + 1; j <= i; ++j) {
			factorial *= j;
			//printf("%d",j);
		}
		//printf("  %d\n\n", factorial);
		each_factorial.push_back(factorial);
		sum += factorial;
		count++;
		//回头记得加一个throw，beyond double size~
	}
	cout << "1+2!+3!+4!+5!+...+n!=" << sum << "   (n=" <<num<< ")" << endl;
}
void check_factorial(const vector<double>& each_factorial) {
		printf("\n\nWhich one do you wanna check?  Please input a number:");
		int a(0);
		cin >> a;//回头在这里加一个错误抛出（Error，beyond 20！！），今天真的不想写了。：（
		vector<double>::const_iterator iter = each_factorial.begin() + a;
		printf("\n\n%d!=%f", a, *iter);
}
