#include"titles_check_functions.h"
#include<math.h>
using namespace std;

//void output_sqrt_num(const int&first, const int&second,long int&n, vector<int> sqrt_num);
//void title_03();

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
