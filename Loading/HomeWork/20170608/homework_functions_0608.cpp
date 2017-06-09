#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct self_length_str
{
	char * str_memo = NULL;
	int count = 0;
};

void value_swap(char * a,char * b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

char* num_alp_divide(char *str) {
	
	char *is_num = str;
	char *is_alp = str;
	while (*is_num != 0 && *is_alp != 0) {
		for (; '0' > *is_num||*is_num > '9'; is_num++);
		for (; '0' <= *is_alp&&*is_alp <= '9'; is_alp++);
		
		//0��1��λ�� ���㽻����
		if(is_alp==str&&is_num==str+1) value_swap(is_alp, is_num);
		else {
			
		}
	}
	return str;
}

void space_exchange(char *src) {
	int src_length = strlen(src);
	int space_count = 0;
	for (int i = 0; i < src_length; i++) {
		if (src[i] == ' ') space_count++;
	}

	int size = src_length + space_count*strlen("%020");
	char *str = (char *)malloc(size);
	strcpy(str, src);
	char *p_space = str;
	char *str_end = str + strlen(src);//�ڶ���ʹ��ʱ�����ַ���Ǳ仯���ַ�����ĩβ��Ӧ�ü����ƽ�����
	// sizeof(str) / sizeof(char) useless.
	for (; p_space<=str+size;p_space++) {
		if (*p_space == ' ') {
			//p_space + strlen("%020");//֮ǰ�ַ������Ƶġ�Ŀ�ĵ�ַ����
			char * from = (char*)malloc(str_end - p_space);
			strncpy(from,p_space+1,str_end - p_space);
			strcpy(p_space + strlen("%020"),from);
			char *temp = "%020";
			for (int i = 0; i < 4; i++) {
				*(p_space + i) = temp[i];
			}
			//�λ�׼������
			free(from);
			from = NULL;
			str_end += strlen("%020")-1;
		}
	}
	//���մ���
	puts(str);
	free(str);
	str = NULL;
}

void del_repetition(char *src) {
	char *repetition = src;
	//���ֵ��һ���ظ���û�е��������������ȴ󣬿ɴ��char�͵�ַ�Ŀռ䡣
	char **rep_pos = (char**)malloc(sizeof(char*)*(strlen(src) + 1));
	//��������һ�α����洢+strcpy����
	int count = 0;
	for (; *repetition != 0; repetition++) {
		if (*repetition != *(repetition + 1)) {
			count++;
			*rep_pos = repetition;
			rep_pos ++;
		}
	}
	*rep_pos = repetition;//���'\0'��ַ

	//��ʼ��rep_pos����ʼλ��
	rep_pos -= count;
	char* str = (char*)malloc(count+1);//����һ��'\0'

	for (; *rep_pos != repetition;rep_pos++,str++) {
		*str = **rep_pos;
	}
	*str = *repetition;
	str -= count;//��λ�׵�ַ��Ҳ�ǻ��մ���
	strcpy(src, str);
	puts(src);
	
	//���մ���
	rep_pos -= count;

	free(str);
	str = NULL;
	free(rep_pos);
	rep_pos = NULL;
}

void get_self_length_string(self_length_str * a_str) {
	//���ô˺����ǵ��ͷſռ䡣
	int count = 0;
	char c;
	char *str_memo = (char*)malloc(50);
	printf("Please input a string :");
	while ((c = getchar()) != '\n') {
		*(str_memo + count) = c;
		count++;//����ʱ�����ڡ�\n��
	}
	*(str_memo + count) = 0;
	realloc(str_memo, count + 1);//��Ϊ�Ǵ��㿪ʼ����������countλ�þ���\n����count�����ַ�����û��\0.(�����ĸ���������λ��)��

	a_str->str_memo = str_memo;
	a_str->count = count;

}

void del() {
	
	self_length_str str_memo;
	get_self_length_string(&str_memo);

	char del;
	printf("Please input the alpha you wanna delete: ");
	cin >> del;

	for (int i = 0; i < str_memo.count&& *(str_memo.str_memo+i)!=0;i++) {
		char *str_end = str_memo.str_memo + str_memo.count;
		if (del == str_memo.str_memo[i]) {
			memmove(str_memo.str_memo + i, str_memo.str_memo + i + 1, str_end - str_memo.str_memo -i);
		}
	}
	
	puts(str_memo.str_memo);
	free(str_memo.str_memo);
	str_memo.str_memo = NULL;
}

void del_space() {
	self_length_str space_str;
	get_self_length_string(&space_str);

	int first_alp = 0, last_alp = space_str.count-1;
	for (; space_str.str_memo[first_alp]==' '&&first_alp < space_str.count; first_alp++);
	for (; space_str.str_memo[last_alp] == ' '&&last_alp != 0; last_alp--);

	space_str.str_memo[last_alp+1] = '\0';
	strcpy(space_str.str_memo, space_str.str_memo + first_alp);

	for (int i = 0; i < space_str.count&& *(space_str.str_memo + i) != 0; i++) {
		if (' ' == space_str.str_memo[i]) {
			int j = i;
			for (; ' ' == space_str.str_memo[j]; j++);
				strcpy(space_str.str_memo + i+1, space_str.str_memo + j);
		}
	}

	puts(space_str.str_memo);

	free(space_str.str_memo);
	space_str.str_memo = NULL;
}

void big(char *arr[], int size, char** big1, char** big2) {
	int compare = 0;
	char*temp;

	if (*arr[0] > *arr[1]) { *big1 = arr[0]; *big2 = arr[1]; }
	else { *big2 = arr[0]; *big1 = arr[1]; }

	for (int i = 2; i < size; i++)
		if (strcmp(*big1, arr[i]) < 0) { 
			*big2 = *big1; 
			*big1 = arr[i]; 
		}
		else if (strcmp(*big2, arr[i]) < 0) {
			*big2 = arr[i]; 
		}

	puts(*big1);
	puts(*big2);
}