#include<stdio.h>
#include<iostream>
//#include"homework_functions_0604.h"
//#include"homework_functions_0606.h"
//#include"homework_functions_0607.h"
//#include"homework_functions_0608.h"
//#include"homework_functions_0609.h"
#include"homework_functions_loading.h"
using namespace std;


void main() {
		
	/*int number = 0;
	link_list * number1=NULL;
	link_list * number2 = NULL;
	char*num_type = "int";

	number1 = get_list_in_order(number1);
	number2 = get_list_in_order(number2);
	number1=list_together(number1, number2);
	output_link_list(number1,num_type);
	link_list last_4_node=last_4(number1);
	printf("The node is: %d.\n", last_4_node.data);*/

	FILE *input = fopen("Student_info.txt","r");
	Students Blues;
	//Blues.input_int();
	Blues.file_init(input);
	Blues.output();

	getchar();
	getchar();
}

/*move-out 2017-06-09*/
/*int x=0, int y=0;
printf("Please input the terminal point you want: ");
cin >> x >> y;

int count = Path_cacl(x,y);

printf("The number of Path is: %d\n", count);*/


//int len = 0;
//link_list *new_list = CreateList_Front();
//output_link_list(new_list);
//len=length(new_list);
//link_list middle_node;
//middle_node=middle(new_list, middle_node);
//printf("%c\n", middle_node.data);

//new_list=reverse(new_list);
//output_link_list(new_list);

//printf("The length of this list is: %d. \n",len);

//new_list = CreateList_End();
//output_link_list(new_list);

//printf("Please input the data you wanna delete: ");
//char deldata;

//for (int i = 0; i < 3; i++) {
//	cin >> deldata;
//	new_list = delete_node(new_list, deldata);
//	output_link_list(new_list);
//}