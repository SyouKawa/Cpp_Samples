#pragma once
#ifndef __STACK_BY_ARRAY_H_
#define __STACK_BY_ARRAY_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MaxSize 50

//用一个数组实现两个栈,一个从左往右，一个从右往左。
typedef struct stack_array {
	int Data[MaxSize];
	int Top1;
	int Top2;
}stack_arr;

void init_stack(stack_arr *stack);
int is_Empty(stack_arr stack, int tag);
int is_Full(stack_arr*stack);
void Push(stack_arr* stack, int item, int tag);
void Pop(stack_arr*stack, int *receive, int tag);
int Top(stack_arr*stack, int tag);

void Middle2End(stack_arr *stack);
#endif // !__STACK_BY_ARRAY_H_

