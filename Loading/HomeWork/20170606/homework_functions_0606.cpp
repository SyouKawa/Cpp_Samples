#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>

using namespace std;
#define dim(x) sizeof(x)/sizeof(x[0])
//dim 无法在函数外传递

void lower2upper() {
	char alphas;
	printf("Please input character(s): ");
	while ((alphas = getchar()) != '\n') {
		cout << (char)(alphas - 32);
	}
	cout << endl;
	//test code/scanf("%c", &alphas);
}

void sign_1(int&num_count,int&alpha_count,int&other_count) {
	char input_sign;
	printf("Please input numbers/characters/others(End with a Enter): ");
	bool quit(0);
	while (quit==0 && (input_sign = getchar())!='\n') {
		if ('0' <= input_sign && input_sign <= '9') num_count++;
		else if (('A' <= input_sign && input_sign <= 'Z') || ('a' <= input_sign && input_sign <= 'z')) alpha_count++;
		else other_count++;
	}
	//cout << " " << num_count << " " << alpha_count << " " << other_count << endl;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Bubble(int count[],int size) {
	for (int i=0; i<size; i++) {
		for (int j(i + 1); j < size; j++)
			if (count[i] < count[j]) swap(count[i], count[j]);
	}
}

void sign_2(int&num_count, int&alpha_count, int&other_count) {
	int count[3] = { 0 };
	sign_1(num_count,alpha_count,other_count);
	count[0] = num_count;
	count[1] = alpha_count;
	count[2] = other_count;
	
	Bubble(count,3);

	for (int i(count[0]); i != 0; i--) {
		for (int j(0); j != 0; j--) printf(" ");
		if (i == count[0]) {
			if (i == count[1] && i == count[2]) printf("  %d      %d      %d  \n",count[0],count[1],count[2]);
			else if (i == count[1]) printf("  %d      %d  \n",count[0],count[1]);
			else printf("  %d  \n", count[0]);
		}
		
		printf("*****");

		if (i <= count[1]+1) {
			printf("  ");
			if (i == count[1] + 1) { printf("  %d  ", count[1]); }
			else printf("*****"); 
		}
			
		if (i <= count[2]+1) {
			printf("  ");
			if (i == count[2] + 1) { printf("  %d  ", count[2]); }
			else printf("*****"); 
			
		}
		printf("\n");
	}

}

void dec_2_bin() {
	printf("Please input a decimal number: ");
	int num=0;
	int one_count=0;
	cin >> num;
	vector<int>bin;
	while (num != 1) {
		int temp = num % 2;
		bin.push_back(temp);
		num /= 2;
	}
	bin.push_back(num);
	reverse(bin.begin(), bin.end());
	printf("The number in binary system is:");
	for (vector<int>::const_iterator iter = bin.begin(); iter != bin.end(); iter++) { 
		if (*iter == 1)one_count++;
		cout << *iter; 
	}
	cout << endl;
	cout << "There are " << one_count << "1 ." << endl;
}

void dec_2_hex() {
	printf("Please input a decimal number: ");
	int num = 0;
	cin >> num;
	vector<int>bin_show;
	while (num > 16) {
		int temp = num % 16;
		bin_show.push_back(temp);
		num /= 16;
	}
	bin_show.push_back(num);
	reverse(bin_show.begin(), bin_show.end());

	char over_nine[6] = { 'a','b','c','d','e','f' };
	for (int i = 0; i <bin_show.size();i++) {
		if (bin_show[i] >= 10) bin_show[i] = over_nine[i];
		else bin_show[i] += 48;
	}
	printf("The number in hex system is: 0x");
	for (vector<int>::const_iterator iter = bin_show.begin(); iter != bin_show.end(); iter++) cout << (char)*iter;
	cout << endl;
}

void bin_2_dec() {
	printf("Please input a binary number: ");
	char num;
	vector<int>bin(0);
	int pos=0;
	int dec = 0;
	while ((num = getchar()) != '\n') {
		num -= 48;
		bin.push_back(num);
	}
	//reverse(bin.begin(), bin.end());
	for (int pos(bin.size()-1),i=0; pos>=0; pos--,i++)
		dec += bin[i]*pow(2, pos);
	printf("The number in decimal system is: %d", dec);
}

void hex_2_dec() {
	printf("Please input a hex number: ");
	char num;
	vector<int>hex(0);
	int pos = 0;
	int dec = 0;

	while ((num = getchar()) != '\n') {
		if ('0' <= num && num <= '9')num -= 48;
		else num -= 87;//'a'=97->  10==97-87;
		hex.push_back(num);
	}
	//reverse(bin.begin(), bin.end());
	for (int pos(hex.size() - 1), i = 0; pos >= 0; pos--, i++)
		dec += hex[i] * pow(16, pos);
	printf("The number in decimal system is: %d", dec);
}

void minus_bin() {
	printf("Please input a decimal number: ");
	int num = 0;
	bool minus = 0;
	int one_count = 0;
	cin >> num;
	vector<int>bin;

	if (num < 0) {
		num = abs(num);
		minus=!minus;
	}

	while (num != 1) {
		int temp = num % 2;
		bin.push_back(temp);
		num /= 2;
	}
	bin.push_back(num);
	
	//凑够字符位
	bin.push_back(0);
	bin.push_back(0);
	bin.push_back(0);
	bin.push_back(0);
	bin.push_back(0);

	reverse(bin.begin(), bin.end());
	
	if (minus) {
		for (int i = 0; i < bin.size(); i++) bin[i]=!bin[i];
		if (bin[bin.size() - 1] == 0) bin[bin.size() - 1] =!bin[bin.size() - 1];
		else {
			bin[bin.size() - 1]=!bin[bin.size() - 1];
			int i = 1;
			while (bin[bin.size() - 1 - i]) {
				bin[bin.size() - 1 - i] =!bin[bin.size() - 1 - i];
				i++;
			}
			bin[bin.size() - 1 - i] =!bin[bin.size() - 1 - i];
		}
	}

	printf("The number in binary system is:");
	for (vector<int>::const_iterator iter = bin.begin(); iter != bin.end(); iter++) {
		if (*iter == 1)one_count++;
		cout << *iter;
	}
	cout << endl;
	cout << "There are " << one_count << "  1 ." << endl;
}

void No5_101() {
	//init_array
	int numbers[101] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i(0); i<50; i++) {
		int temp(0);
		temp = rand() % 101;
		numbers[i] = temp;
		numbers[100-i] = temp;
	}
	numbers[50] = 999;

	//find_number
	int find=0;
	for (int i = 0; i < 50; i++) {
		find^=(numbers[i] ^ numbers[100-i]);
	}
	find ^= numbers[50];
	cout << find << endl;
}

int Day_th(int *year, int *month, int *date) {
Label:
	printf("%d-%d-%d\n\n", *year, *month, *date);
	int day_sum(0);
	for (int i=1;i<*month;i++) {
		if (2 != i) {
			if (i % 2 == 0 && i <= 7) day_sum+=30;
			if (i % 2 != 0 && i <= 7) day_sum += 31;
			if (i % 2 == 0 && i > 7 && i <= 12) day_sum += 31;
			if (i % 2 != 0 && i > 7 && i <= 12) day_sum += 30;
		}
		else if (2 == i) {
			if (*year % 4 == 0 && *year % 100 != 0 || *year % 400 == 0) day_sum += 29;
			else day_sum += 28;
		}
		else {
			printf("ERROR MONTH.\n");
			puts("Please check and input again.");
			goto Label;
		}
	}
	day_sum += *date;
	//printf("The sum of days is:%d\n", day_sum);
	return day_sum;
}

void year2year_day_sum() {
	int year1(0), month1(0), date1(0);
	int year2(0), month2(0), date2(0);
	
	int day_sum1 = 0;
	int day_sum2 = 0;
	int result = 0;

	printf("Please input year1 month1 date1( divide with space): ");
	cin >> year1 >> month1 >> date1;
	printf("Please input year2 month2 date2( divide with space): ");
	cin >> year2 >> month2 >> date2;
	
	day_sum1 = Day_th(&year1, &month1, &date1);
	day_sum2 = Day_th(&year2, &month2, &date2);
	//if (month2<=2&&(year2 % 4 == 0 && year2 % 100 != 0 || year2 % 400 == 0)) add_days-=1;

	result = (year2 - year1) * 365 + day_sum2 - day_sum1+(year2 - year1) / 4;
	printf("The difference between %d-%d-%d and %d-%d-%d is :%d\n", year1, month1, date1, year2, month2, date2,result);
}

void what_Day_is_it_today() {
	int year(0), month(0), date(0);
	int day_sum = 0;
	int week(0);

	//好长啊，写完函数再回来改。/char week_day[7][3] = { {'S','U','N'},{'','',''},{'','',''},{,,,},{,,,},{,,,},{,,,} };
	vector<string>week_day = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

	printf("Please input year1 month1 date1( divide with space): ");
	cin >> year >> month >> date;
	day_sum = Day_th(&year, &month, &date);
	week = day_sum / 7;
	if (week % 7 != 0) week += 1;
	
	cout <<"This week is the "<< week <<"th week,and today is "<< week_day[(day_sum-1)%7] <<" ."<< endl;
}

void day_2_date() {
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year(0), month(0), date(0);
	int day_sum = 0;
	int add_days = 0;
	printf("Please input year month date( divide with space): ");
	cin >> year >> month >> date;
	day_sum = Day_th(&year, &month, &date);
	printf("Please input the number of days you wanna add: ");
	cin >> add_days;
	day_sum += add_days;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) month_days[1] = 29;

	//day->date
	int mon_pos(0);
	for (;mon_pos<12&&day_sum>=month_days[mon_pos];mon_pos++) {
			day_sum -= month_days[mon_pos];
	}
	if (0 == day_sum) day_sum = month_days[mon_pos-1];
	printf("From %d-%d-%d ,add %d day ->%d-%d-%d", year, month, date, add_days, year, mon_pos, day_sum);
	//cout << mon_pos+1 << " "<< day_sum << endl;
}

void month_Calendar(int year,int month) {
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<string>week_day = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	int day_sum = 0;
	//printf("Please input year month date( divide with space): ");
	//cin >> year >> month;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) month_days[1] = 29;

	//1. init day_sum->this month : 1th (  Day  )
	for (int i=0;i<month-1;i++) {
		day_sum += month_days[i];
	}

	//2.output Calendar
	printf("\n\n%d  SUN MON TUE WED THU FRI SAT\n   ", month);
	int today(0);
	int line_in_count(0);
		
	
	for (int i(1); i <= month_days[month - 1]; i++) {
		day_sum += i;
		
		if(i==1) {//   1st <---> week_day tran
			today = (day_sum - 1) % 7;
			for (int j(0); j <= week_day.size(); j++) {
				if (today == j) {
					printf("%3d ", i);
					line_in_count++;
					break;
				}
				else {	//print space
					printf("    ");
					line_in_count++;
				}
			}
		}
		if (line_in_count == 7) { 
			printf("\n   "); 
			line_in_count = 0; 
		
		}
		else if(i!=1) {
			printf("%3d ", i);
			line_in_count++;
		}

	}
	printf("\n");


}

void The_Calendar() {
	int year = 0;
	int month_left = 0;
	int month_right = 0;
	int day_sum_left = 0;
	int day_sum_right = 0;
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<string>week_day = { "SUN","MON","TUE","WED","THU","FRI","SAT" };
	printf("Please input the year whose calendar you want to know:");
	cin >> year;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) month_days[1] = 29;


	printf("|------------------The Calendar of Year 2014 ---------------------|\n");
	for (int week_header = 1; week_header <= 6; week_header++) {
		printf("|%2d  SUN MON TUE WED THU FRI SAT  %2d  SUN MON TUE WED THU FRI SAT |\n", week_header, week_header + 6);
		//printf("|%2d  SUN MON TUE WED THU FRI SAT  %2d  SUN MON TUE WED THU FRI SAT |\n", week_header, week_header + 6);
		month_left = week_header;
		month_right = week_header + 6;

		for (int i = 0; i < month_left - 1; i++) {
			day_sum_left += month_days[i];
		}
		int today_left = 0;
		int today_right = 0;
		int line_in_count = 0;
		int line(0);

		//pos
		int left = 1;
		int right = 1;
		int left_in = 0;
		int right_in = 0;

		//左侧
Label:
 		printf("|    ");
		
		for (int i = 0; i < month_left - 1; i++) {
			day_sum_left += month_days[i];
		}

		for (; left <= month_days[month_left - 1]; left++) {
			day_sum_left += left;
			today_left = (day_sum_left - 1) % 7;
			if (left == 1) {
				for (; left_in <= week_day.size(); left_in++) {
					if (today_left == left_in) {
						printf("%3d ", left);
						line_in_count++;
						break;
					}
					else {
						printf("    ");
						line_in_count++;
					}
				}
			}
			else {
				printf("%3d ", left);
				line_in_count++;
				if (left == month_days[month_left - 1]) {
					for (int i((day_sum_right - 1) % 7); i < week_day.size()-1; i++) {
						printf("    ");
						line_in_count++;
					}
				}
			}
			if (line_in_count >= 7) {line_in_count = 0; break; }// < -------- - 跳出左侧输出
		}
		printf("     ");

		//右侧
		for (int i = 0; i < month_left - 1; i++) {
			day_sum_right += month_days[i];
		}

		for (; right <= month_days[month_right - 1]; right++) {
			day_sum_right += right;
			today_right = (day_sum_right - 1) % 7;
			if (right == 1) {
				for (; right_in <= week_day.size(); right_in++) {
					if (today_right == right_in) {
						printf("%3d ", right);
						line_in_count++;
						break;
					}
					else {
						printf("    ");
						line_in_count++;
					}
				}
			}
			else {
				printf("%3d ", right);
				line_in_count++;
				if (right == month_days[month_right - 1]) {
					for (int i((day_sum_right - 1) % 7); i < week_day.size() - 1; i++) {
						printf("    ");
						line_in_count++;
					}
				}
			}
			if (line_in_count == 7) { printf("|"); line_in_count = 0; break; }// < -------- - 跳出左侧输出
		}
		printf("\n");
		line++;
		if (line < 6) { left++;right++; goto Label; }//<------------回到左侧继续打印
		else {
			left = 1;
			right = 1;
			left_in = 0;
			right_in = 0;
			line = 0;
		}
	}//左右块
	//printf("\n");
}