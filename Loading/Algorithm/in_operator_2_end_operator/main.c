#include"stack_by_array.h"

void main() {
	stack_arr num;
	init_stack(&num);
	
	Middle2End(&num);

	printf("\n");
	system("pause");
}