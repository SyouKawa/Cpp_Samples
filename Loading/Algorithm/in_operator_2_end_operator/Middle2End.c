#include"stack_by_array.h"

void Middle2End(stack_arr *stack) {
	char calc_str[20] = "a+b*c+(d*e+f)*g";
	//memset(calc_str, 0, sizeof(calc_str));
	//printf("Please input a calc-str:");
	//scanf("%s", calc_str);
	printf("%s", calc_str);
	printf("\n");
	for (int i = 0; calc_str[i] != 0; i++) {

		if (40 <= calc_str[i] && calc_str[i] <= 43) {
			if (is_Empty(*stack, 2)) { Push(stack, (int)calc_str[i], 2); continue; }
			if (calc_str[i] <=Top(stack, 2)) {//����ջ�ģ����ȼ��Ƚϸ� 
				if (calc_str[i] == (int)')') {//ֱ�� �� ֮ǰ���������������
					for (; !(is_Empty(*stack, 2)) && Top(stack, 2) != (int)'('; Pop(stack, stdout, 2))
						printf("%c", Top(stack, 2));
					Pop(stack, stdout, 2);//���� ������ѭ����������� 
				}
				if(calc_str[i]!=(int)')') Push(stack, (int)calc_str[i], 2);//ֱ����ջ
			}
			if (calc_str[i]>Top(stack,2)) {//����ջ�ģ����ȼ��Ƚϵ͵����				
				if (Top(stack, 2) == (int)'(') { Push(stack, calc_str[i], 2); continue; }//���ǰ���ǣ����Ͱѣ���һ���ڲ�ջ�ף�ֱ��ѹջ��һ��Ҫcontinue����Ȼ�������ѭ������ϻ���һ�θ������
				for (; !(is_Empty(*stack, 2)) && calc_str[i] >= Top(stack, 2)&&Top(stack,2)!=(int)'('; Pop(stack, stdout, 2)) {
					printf("%c", Top(stack, 2));
				}
			Push(stack, calc_str[i], 2);				
			}
		}
		if (97 <= calc_str[i] && calc_str[i] <= 122) {
			Push(stack, (int)calc_str[i], 1);
			printf("%c", stack->Data[stack->Top1]);
			Pop(stack, stdout, 1);
		}
	}
	while (!is_Empty(*stack, 2)) {
		printf("%c", Top(stack, 2));
		Pop(stack, stdout, 2);
	}
}