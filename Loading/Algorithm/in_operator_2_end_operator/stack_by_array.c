#include"stack_by_array.h"


void test_stack_by_array() {
	stack_arr num;
	init_stack(&num);
	int item=0;
    	while (item != -1) {
		scanf("%d", &item);
		Push(&num, item, 1);
	}
	printf("\n");
	Pop(&num, &item, 1);//把那个不要的-1先弹出来。
	while (!is_Empty(num,1)) {
		Pop(&num, &item, 1);
		printf("%d\n", item);
	}
	system("pause");
}

void Push(stack_arr* stack, int item, int tag) {
	if (stack->Top1 == stack->Top2) {
		printf("Full Stack.\n");
		return;
	}
	if (tag == 1) stack->Data[++stack->Top1] = item;
	if (tag == 2) stack->Data[--stack->Top2] = item;
}

void Pop(stack_arr*stack, int *receive, int tag) {
	if (tag == 1 && stack->Top1 == -1) printf("Stack_1 is Empty.\n");
	if (tag == 2 && stack->Top2 == MaxSize)  printf("Stack_2 is Empty.\n");

	if (tag == 1)*receive = stack->Data[stack->Top1--];
	if (tag == 2)*receive = stack->Data[stack->Top2++];
}

int Top(stack_arr*stack,int tag) {
	if (tag == 1) return stack->Data[stack->Top1];
	if (tag == 2) return stack->Data[stack->Top2];
}

void init_stack(stack_arr *stack) {
	memset(stack->Data, 0, MaxSize*sizeof(int));
	stack->Top1 = -1;
	stack->Top2 = MaxSize;
}

int is_Empty(stack_arr stack, int tag) {
	if (tag == 1 && stack.Top1 == -1) return 1;
	if (tag == 2 && stack.Top2 == MaxSize) return 1;
	return 0;
}

int is_Full(stack_arr*stack) {
	if (stack->Top1 == stack->Top2) {
		printf("Full Stack.\n");
		return 1;
	}
	return 0;
}