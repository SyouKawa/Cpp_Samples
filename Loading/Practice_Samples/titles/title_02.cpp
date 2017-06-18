#include<iostream>
using namespace std;

#define per 100000
#define bonus1 10000
#define bonus2 10750
#define bonus4 20750
#define bonus6 26750
#define bonus10 32750

void main() {
	
	long int profit = 0;
	int bonus = 0;
	puts("Please input profit in all: ");
	cin >> profit;// "%ld", &profit);
	int situation = profit / per;
	bool finish = 0;
	for (;;) {
		if (situation == 3) situation = 2;
		if (situation == 5) situation = 4;
		if (situation == 7 || 8 || 9) situation = 6;
		if (situation > 10) situation = 10;

		switch (situation)
		{
		case 0:bonus = profit*0.1; break;
		case 1:bonus = bonus1 + int((profit - 100000)*0.075); finish = 1; break;
		case 2:bonus = bonus2 + int((profit - 200000)*0.05); finish = 1; break;
		case 4:bonus = bonus4 + int((profit - 400000)*0.03); finish = 1; break;
		case 6:bonus = bonus6 + int((profit - 600000)*0.015); finish = 1; break;
		case 10:bonus = bonus10 + int((profit - 1000000)*0.01); finish = 1; break;
		default:
			cout << "ERROR!! Please check your input again." << endl;
		}
		if (finish) break;
	}

	cout<<"Your bonus is:"<<bonus<<" Thanks for using. :-)";
	
	getchar();
	getchar();
}