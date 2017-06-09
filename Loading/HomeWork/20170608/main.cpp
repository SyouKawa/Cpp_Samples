#include<stdio.h>
#include<iostream>
//#include"homework_functions_0604.h"
//#include"homework_functions_0606.h"
//#include"homework_functions_0607.h"
//#include"homework_functions_0608.h"
#include"homework_functions_0609.h"
using namespace std;


void main() {
	int x=0, int y=0;
	printf("Please input the terminal point you want: ");
	cin >> x >> y;

	int count = Path_cacl(x,y);

	printf("The number of Path is: %d\n", count);
	

	getchar();
	getchar();
}