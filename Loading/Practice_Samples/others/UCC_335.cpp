#include<iostream>
#include<stdio.h>
using namespace std;

int add(int num1, int num2) { return num1 + num2; }
int substract(int num1, int num2) { return num1 - num2; }

typedef int(*fptrOperation)(int, int);

int(*operations[128])(int, int) = { NULL };

void initializeOperationArray() {
	operations['+'] = add;
	operations['-'] = substract;
}

int evaluateArray(char opcode, int num1, int num2) {
	fptrOperation operation;
	operation = operations[opcode];
	return operation(num1, num2);
}

int compute(fptrOperation opertation,int num1,int num2) {
	return opertation(num1, num2);
}

fptrOperation select(char opcode) {
	switch (opcode)
	{
	case'+':return add; break;
	case'-':return substract; break;
	}
}

int evaluate(char opcode, int num1, int num2) {
	fptrOperation operation = select(opcode);
	return operation(num1, num2);
}

void uuc335_test() {
	printf("%d\n", evaluateArray('+', 5, 6));
	printf("%d\n", evaluateArray('-', 5, 6));
}