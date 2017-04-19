#include"titles_check_functions.h"
#include<math.h>
using namespace std;

void output_sqrt_num(const int&first, const int&second,long int&n, vector<int> sqrt_num);
void title_03();

void title_03() {
	cout << "Assuming exist x that is a sqrt-num." << endl << endl;
	puts("Now you can input two add-num to get a sqrt-num.");
	int first(0), second(0);
	printf("\nPlease input the first add-num: ");
	cin >> first;
	printf("\nPlease input the second add-num: ");
	cin >> second;
	//debug using/ cout << "first: " << first << "  second: " << second << endl;

	vector<int> sqrt_num{0};
	long int n(0);
	printf("Please input the range of searching : ");//code later : throw beyond error.
	cin >> n;

	output_sqrt_num(first,second,n,sqrt_num);

	system("pause");
}
void output_sqrt_num(const int&first,const int&second,long int&n,vector<int> sqrt_num) {
	int a(0), b(0);
	for (long int x = 1; x < n; ++x) {
		a = sqrt(x + first);
		b = sqrt(x + second);
		//debug using/ if ((b - a)*(b + a) == double(second - first)) sqrt_num.push_back(x);
		//debug using/ if(a*a==x+100 && b*b==x+268) sqrt_num.push_back(x);
		if ((pow(b, 2) - pow(a, 2)) == (second - first)) sqrt_num.push_back(x);
	}
	printf("The sqrt-num can be: ");
	for (vector<int>::iterator iter = sqrt_num.begin(); iter != sqrt_num.end(); ++iter) {
		if (iter == sqrt_num.end() - 1) { printf("%ld .", *iter); break; }
		printf("%ld, ", *iter);
	}
	printf("\n\n");
}