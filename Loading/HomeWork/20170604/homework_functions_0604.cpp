#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<random>
#include<algorithm>
#include"homework_functions_0604.h"

using namespace std;

void multi_result() {
	int multi_result(0);
	for (int num(1); num < 10; num++) {
		for (int line(1); line <= num; line++) {
			multi_result = num*line;
			printf("%dX%d=%d  ", line, num, multi_result);
		}
		cout << endl;
	}
}

void print_diamond_Basic() {
	int num = 0;// middle line sum

	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines
	int simple_line_sum = num - lines; //eg:7-3=4->the first line's sum
									   //int space_count = num - simple_line_sum; //eg:3 spaces + 4 lines_sum=7
									   //int star_count = simple_line_sum - space_count;

	printf("\nOK,you need %d up-lines,and %d down-lines.\n\n", lines, lines);
	cout << "And like this:" << endl;

	for (int i = 0; i < lines; ++i) {
		for (int j = num - simple_line_sum; j != 0; --j) printf(" ");
		for (int j = simple_line_sum - (num - simple_line_sum); j != 0; --j)printf("*");
		simple_line_sum++;
		printf("\n");
		//printf("%d", simple_line_sum);
	}

	for (int i = 0; i < num; ++i) printf("*");
	printf("\n");

	for (int i = 1; i <= lines; ++i) {
		for (int j = 0; j<i; ++j) printf(" ");
		for (int j = 0; j<simple_line_sum - (2 * i); ++j)printf("*");
		printf("\n");
	}
	system("pause");
}

void print_diamond_1() {
	int num = 0;// middle line sum

	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines
	int simple_line_sum = num - lines; //eg:7-3=4->the first line's sum
									   //int space_count = num - simple_line_sum; //eg:3 spaces + 4 lines_sum=7
									   //int star_count = simple_line_sum - space_count;

	printf("\nOK,you need %d up-lines,and %d down-lines.\n\n", lines, lines);
	cout << "And like this:" << endl;

	for (int i = 0; i <= lines; ++i) {
		for (int j = num - simple_line_sum; j != 0; --j) printf(" ");

		for (int j = simple_line_sum - (num - simple_line_sum); j != 0; --j) {
			if(j%2==0)printf("*");
			else printf(" ");
		}
		simple_line_sum++;
		printf("\n");
		//printf("%d", simple_line_sum);
	}

	for (int i = 0; i < num; ++i) {
		if (i % 2 == 0)printf("*");
		else printf(" ");
	}
	printf("\n");

	for (int i = 1; i <= lines; ++i) {
		for (int j = 0; j<i; ++j) printf(" ");
		for (int j = 0; j < simple_line_sum - (2 * i); ++j) {
			if (j % 2 == 0)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	system("pause");
}

void print_diamond_2() {
	int num = 0;// middle line sum
	cout << "Please input the number of * you want :";
	cin >> num;

	int lines = num / 2; // up-lines_sum
	
	//  I 和 II 象限
	int x = 0 - lines;
	int y = lines;
	int position = lines;

	for (;y>=0;y--) {
		for (x=0-lines;x<0;x++) {//第二象限
			if (x - y == 0-position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//第一象限
			if (x + y == position) printf("*");
			else printf(" ");
		}
		cout << endl;
	}

	//  III 和 IV 象限
	for (; y <= 0; y--) {
		for (x = 0 - lines; x<0; x++) {//第三象限
			if ((x+y) == 0 - position) printf("*");
			else printf(" ");
		}
		for (; x <= lines; x++) {//第四象限
			if ((y-x) == 0- position) printf("*");
			else printf(" ");
		}
		cout << endl;
		if (0 - y == num - 1) break;
	}
}

void print_diamond_3() {
	int middle(0);
	printf("Please input the length of middle you want:");
	cin >> middle;
	//part-1
	int trangle_bottom = ((middle + 1) / 2)+1;
	int bottom_flower = trangle_bottom / 2;
	for (int line(bottom_flower),space(bottom_flower); line != 0; line--, space--) {
			for (int i(space); i != 0; i--) printf(" ");

		//middle part
		for (int flower(trangle_bottom-2*space);flower!=0;flower--) {
			if (flower % 2 == 0) printf(" ");
			else printf("*");
		}

		printf(" ");

		for (int j(space); j != 0; j--) printf(" ");

		//double:
		for (int i(space); i != 0; i--) printf(" ");

		//middle part
		for (int flower(trangle_bottom - 2 * space); flower != 0; flower--) {
			if (flower % 2 == 0) printf(" ");
			else printf("*");
		}

		printf(" ");

		for (int j(space); j != 0; j--) printf(" ");

		cout << endl;
	}

	//part-2
	for (int line(middle+3),line_num(0); line >= (middle+3+1) / 2; line--,line_num++) {
		for (int i(line_num); i != 0; i--)printf(" ");
		for (int this_line(line-line_num); this_line > 0; this_line--) {
			if (this_line % 2 == 0)printf(" ");
			else printf("*");
		}
		cout << endl;
	}
}

void public_elements_1A() {
	
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	vector<int>numbers_1;
	vector<int>numbers_2;

	srand((unsigned int)time(NULL));
	for (int i(0);i<size;i++) {
		int temp(0);
		time_t times;
		temp = rand() % 51;//n=rand()%(Y-X+1)+X; n为X~Y之间的随机数
		numbers_1.push_back(temp);
	}
	srand((unsigned int)time(NULL));
	for (int i(0); i<size; i++) {
		int temp(0);
		temp = rand() % 51;//n=rand()%(Y-X+1)+X; n为X~Y之间的随机数
		numbers_2.push_back(temp);
	}

	for (vector<int>::const_iterator iter=numbers_1.begin();iter!=numbers_1.end();++iter) {
		cout << *iter << " ";
	}
	cout << endl;
	for (vector<int>::const_iterator iter = numbers_2.begin(); iter != numbers_2.end(); ++iter) {
		cout << *iter << " ";
	}
	cout << endl;
}

void public_elements_1A2() {
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	vector<int>numbers_1;
	vector<int>numbers_2;
	
	default_random_engine generator;
	uniform_int_distribution<int> dis(0, 50);
	for (int i = 0; i < size; i++)
		numbers_1.push_back(dis(generator));
	for (int i = 0; i < size; i++)
		numbers_2.push_back(dis(generator));

	vector<int>same_nums(0);
	for (int i(0);i<size;i++)
		for (int j(0); j < size; j++)
			if (numbers_1[i] == numbers_2[j]) same_nums.push_back(numbers_1[i]);
	sort(same_nums.begin(), same_nums.end());
	vector<int>::iterator pos;
	pos = unique(same_nums.begin(), same_nums.end());
	same_nums.erase(pos, same_nums.end());

	puts("There are same numbers: ");
	for (vector<int>::const_iterator iter = same_nums.begin(); iter != same_nums.end(); ++iter) {
		cout << *iter << " ";
	}
}

void public_elements_group() {
	int group_nums(0);
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	printf("Please input the number of groups you want: ");
	cin >> group_nums;//先生成两个，获得相同数组，清空储存，再载入新的随机数组，循环判别相同数组。
	vector<int>same_nums(0);

	//source group:
	int *group_src = new int[size];
	int *group_compare = new int[size];
	
	default_random_engine generator;
	uniform_int_distribution<int> dis(0, 50);
	for (int i = 0; i < size; i++)
		*(group_src+i)=dis(generator);
	for (int i = 0; i < size; i++)
		*(group_compare + i) = dis(generator);
		
	for (int i(0); i<size; i++)
		for (int j(0),size_in(size); j < size; j++){
			if (group_src[i] == group_compare[j])	same_nums.push_back(group_src[i]);
			}
				
		sort(same_nums.begin(), same_nums.end());

		vector<int>::iterator pos;
		pos = unique(same_nums.begin(), same_nums.end());
		same_nums.erase(pos, same_nums.end());

		delete group_src;
		delete group_compare;
		vector<int>left_group(0);

	for(int groups(group_nums-2);groups!=0;groups--) {
		for (int i = 0; i < size; i++)
			left_group.push_back(dis(generator));
		for (vector<int>::const_iterator iter=left_group.begin(),iter2=same_nums.begin(); iter!=left_group.end(),iter2!=same_nums.end(); iter++,iter2++) {
			if (find(left_group.begin(), left_group.end(), *iter2) == left_group.end()) same_nums.erase(iter2,iter2);
			else continue;
		}
	}
	for (vector<int>::const_iterator iter = same_nums.begin(); iter != same_nums.end(); iter++) cout << *iter << endl;
}

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void Insertion(vector<int>&numbers) {
	for (int j(1); j < numbers.size(); j++) {
		int temp = numbers[j];
		int i = j - 1;
		for (; i >= 0 && numbers[i]>temp; i--) numbers[i + 1] = numbers[i];
		numbers[i + 1] = temp;
	}
}

void sort_4_max_and_then() {
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	vector<int>numbers;
	srand((unsigned int)time(NULL));
	for (int i(0); i < size; i++) {
		int temp(0);
		temp = rand() % 51;//n=rand()%(Y-X+1)+X; n为X~Y之间的随机数
		numbers.push_back(temp);
	}
	Insertion(numbers);
	for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); iter++) cout << *iter << endl;
	printf("The Max num is: %d .\n", numbers[size - 1]);
	size -= 1;
	while (numbers[size] == numbers[size--]);//防止最后几项相同。
	printf("The second num is: %d .",numbers[size]);
}

void beyond_half() {
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	vector<int>numbers;
	srand((unsigned int)time(NULL));
	for (int i(0); i < size; i++) {
		int temp(0);
		temp = rand() % 101;
		numbers.push_back(temp);
	}
	int the_num = rand() % 101;//被设置的数
	for (int i(0); i < size / 2; i++) {
		int random_pos = rand() % size;
		numbers[random_pos] = the_num;
	}
	//show the num/cout << the_num;

	//find the num
	int set_num = numbers[0];
	int count(1);
	for (int i(1); i < size; i++) {	
		if (numbers[i] == set_num)
				count++;
			else{
				count--;
				if (count < 0){
					set_num = numbers[i];
					count = 1;
				}
			}
	}
	cout << set_num << endl;
}

void sort_6_abs_min() {
	int size(0);
	printf("Please input the size of array you want: ");
	cin >> size;
	vector<int>numbers;
	srand((unsigned int)time(NULL));
	for (int i(0); i < size; i++) {
		int temp(0);
		temp = rand() % 51;//n=rand()%(Y-X+1)+X; n为X~Y之间的随机数
		numbers.push_back(temp);
	}
	Insertion(numbers);
	for (vector<int>::const_iterator iter = numbers.begin(); iter != numbers.end(); iter++) cout << *iter << endl;
	int Center = (size - 1) / 2;
	int abs_min_1 = numbers[Center + 1] - numbers[Center];
	int abs_min_2 = numbers[Center] - numbers[Center-1];
	printf("The min abs is %d .",(abs_min_1 > abs_min_2) ? abs_min_2 : abs_min_1);
}

void No7_diff_or() {
	int check_array[1001] = { 0 };
	for (int i(0); i < sizeof(check_array) / sizeof(int); i++) check_array[i] = i;
	srand((unsigned int)time(NULL));
	int change_num = rand() % 1001;
	check_array[change_num] = check_array[change_num - 1];
	//show the num/printf("%d",check_array[change_num - 1]);
	
	//find the changed num
	int find_num = check_array[0];
	int basic[1001] = { 0 };
	for (int i(0); i < sizeof(check_array) / sizeof(int); i++){
		//find_num ^=check_array[i];
		if (basic[check_array[i]] == 1)
		{
			printf("The same num (changed num)is %d\n", check_array[i-1]);
			//printf("%d\n", i);
			break;
		}
		basic[check_array[i]] = 1;
	}
}