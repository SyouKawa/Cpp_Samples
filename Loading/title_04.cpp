#include<iostream>
#include<unordered_map>
#include<string>//attention!
#include<stdio.h>
using namespace std;

int & day_handle(int & day_sum);
int & month_handle(string&input, const unordered_map<string, int> & month2day, int & day_sum);
int & year_handle(int&year, string & month, int &day_sum);

void main() {
	
	unordered_map<string, int>month2day = { {"January",31},{"February",28},{"March",31},{"April",30},{"May",31},{"Juny",30},
								{"July",31},{"August",31},{"September",30},{"October",31},{"November",30},{"December",31} };
	//dont change Feb. just +/- 1 after judging the year.

	/*/debug using/ cout << month2day.size() << endl;
	for (unordered_map<string,int>::const_iterator iter=month2day.begin();iter!=month2day.end();++iter) {
		cout<<iter->first << ":" << iter->second << "days." << endl;
	}*/
	string input;
	int day_sum(0);
	int year(0);

	for (int flag=1;flag==1;) {
		day_sum = month_handle(input, month2day, day_sum);
		day_sum = year_handle(year, input, day_sum);
		day_sum=day_handle(day_sum);

		cout << "The date is No." << day_sum << " day in " << year << " year." << endl;
		cout << endl;
		printf("Next Date input or Quit?(1/0): ");
		cin >> flag;
		day_sum = 0;
	}
	cout << "\n\nThanks for using. : )" << endl;
	system("pause");
}

int & year_handle(int&year,string & month,int &day_sum) {
	printf("Please input the year: ");
	cin >> year;
	if (year % 4 == 0 && month != "January"&& month != "February") day_sum += 1;

	return day_sum;
}

int & month_handle(string&input,const unordered_map<string,int> & month2day,int & day_sum ) {
	printf("\nPlease input the month: ");
	cin >> input;
	//debug_use/ map<string, int>::const_iterator iter = month2day.find(input);
	//debug_use/ cout << iter->first << " : " << iter->second << endl;
	for (unordered_map<string, int>::const_iterator iter = month2day.begin(); iter != month2day.find(input); ++iter) {
		day_sum += iter->second;
		//debug using/ cout << day_sum << endl;
	}
	return day_sum;
}

int & day_handle(int & day_sum) {
	printf("Please input the day in month:    th.\b\b\b\b\b\b");
	int day(0);
	cin >> day;
	day_sum += day;
	return day_sum;
}
