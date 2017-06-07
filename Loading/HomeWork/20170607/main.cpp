#include<stdio.h>
#include<iostream>
//#include"homework_functions_0604.h"
#include"homework_functions_0606.h"
#include"homework_functions_0607.h"
using namespace std;


void main() {
	char src[50] ="Coding ";
	char str[50] = {0};
	
	char smaller[] = "Catch sth.";
	char bigger[] = "Fun me.";
	char equal[] = "Coding ";
	
	//mystrcpy(src, str);
	/*int result = 0;
	result = mystrcmp(src,smaller);
	cout << result << endl;
	result = mystrcmp(src, equal);
	cout << result << endl;
	result = mystrcmp(src, bigger);
	cout << result << endl;
	
	mystrcat(src,bigger);*/
	size_t length(0);
	length=mystrlen(src);
	cout << length << endl;

	char input[] = "    hello         world  how   are   you    ";
	int count =  split_input(input);

	puts("\n\n");

	char reverse[] = "I    am  a  student";
	reverses(reverse);

	getchar();
	getchar();
}

/*move-out* *2017-06-04*/
//multi_result();
//print_diamond_Basic();
//print_diamond_1();
//print_diamond_2();
//print_diamond_3();
//public_elements_1A2();
//public_elements_group();
//sort_4_max_and_then();
//sort_6_abs_min();
//No7_diff_or();
//beyond_half();
//system("pause");

/*move-out* *2017-06-06*/
//lower2upper();
//int num_count(0),alpha_count(0),other_count(0);
//sign_1(num_count,alpha_count,other_count);
//sign_2(num_count, alpha_count, other_count);
//dec_2_bin();
//bin_2_dec();
//dec_2_hex();
//hex_2_dec();
//minus_bin();
//No5_101();
//Day_th();
//year2year_day_sum();
//what_Day_is_it_today();
//day_2_date();
//month_Calendar();
//The_Calendar();