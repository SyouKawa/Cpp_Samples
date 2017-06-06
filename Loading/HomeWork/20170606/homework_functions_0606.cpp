#include<stdio.h>
#include<iostream>
#include<vector>
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
	cout << " " << num_count << " " << alpha_count << " " << other_count << endl;
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
		if (i == count[0]) printf("  %d  \n", count[0]);
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

void Day_th() {
	int year(0), month(0), date(0);
	printf("Please input year month date( divide with space): ");
	cin >> year >> month >> date;
	printf("%d-%d-%d", year, month, date);
}