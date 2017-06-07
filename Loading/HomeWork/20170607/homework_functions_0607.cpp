#include<stdio.h>
#include<iostream>
#include"homework_functions_0607.h"

using namespace std;

void mystrcpy(char*from,char*to) {
	for (size_t i=0;from[i]!='\0';i++) {
		to[i] = from[i];
	}
	//check code/puts(to);
}

int mystrcmp(char*src,char*cmp) {
	for (rsize_t i = 0;;i++) {
		if (src[i] == cmp[i]) {
			if (src[i] == 0) return 0;
			continue;
		}
		else {
			if (src[i] < cmp[i]) return 1;
			if (src[i] > cmp[i]) return -1;
		}
	}
}

void mystrcat(char*before,char*after) {
	puts(before);
	puts(after);

	size_t i = 0;
	for (; before[i] != 0; i++);
	for (size_t j = 0; after[j] != 0; j++, i++) {
		before[i] = after[j];
		before[i + 1] = 0;
	}
	//return before;
	puts(before);
}

size_t mystrlen(char*str) {
	size_t i = 0;
	for (; str[i] != 0; i++);
	return i;
}

bool ispace(const char c) {
	return (c == ' ');
}

int split_input(char *str) {
	size_t i=0;
	int count=0;
	while (str[i] != 0) {
		for (; str[i] != 0 && ispace(str[i]); ++i);
		size_t j = i;
		for (; str[j] != 0 && !ispace(str[j]); ++j);
		if (i != j) {
			char temp[50] = {0};
			for (int k=0;i!=j;k++,i++) {
				temp[k] = str[i];
			}
			puts(temp);
			count++;
		}

		i = j;
	}
	printf("%d", count);
	return count;
}

void swap_act(char*a,char*b) {
	char temp = ' ';
	temp = *a;
	*a = *b;
	*b = temp;
}

void reverses(char *str) {
	size_t size = 0;
	size=mystrlen(str);
	for (size_t i=0;i<size/2;i++) {
		swap_act((str+i),(str+size-1-i));
	}
	
	size_t i = 0;
	while (str[i] != 0) {
		for (; str[i] != 0 && ispace(str[i]); ++i);
		size_t j = i;
		for (; str[j] != 0 && !ispace(str[j]); ++j);
		if (i != j) {
			int times = (j - i) / 2;
			for (int k = 0; k<times; k++) {
				if (k == 0) times += 1;
				swap_act((str + i + k), (str + j - k));
			}
		}
		i = j;
	}
	puts(str);
}