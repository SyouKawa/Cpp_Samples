#pragma once
#ifndef __HOMEWORK_FUNCTIONS_LOADING_H_
#define __HOMEWORK_FUNCTIONS_LOADING_H_

struct link_list
{
	char data=0;
	link_list* next=NULL;
};

struct Students
{
	char IDcode[12] = "20170604400";
	char name[10]="XXXX XXXX";
	int count = 0;
	char scores_s[3][4] = {"000","000","000"};
	int scores[3] = { 0 };
	int sum = 0;

	void input_int() {
		printf("Please input the data of this student(IDcode,name,math,english,chinese, divide with ','): ");
		scanf("%s", &IDcode);
		scanf("%s", &name);
		scanf("%d %d %d", scores, scores+1, scores+2);
	}
	void file_init(FILE *file_in) {
		char c='N';
		int i = 0;
		for (; i<11;i++) {
			c = fgetc(file_in);
			IDcode[i] = c;
		}
		IDcode[i] = '\0';
		i = 0;
		c = fgetc(file_in);
		while (c == ' ') { c = fgetc(file_in); }
		for (; c!=' '; i++) {
			name[i] = c;
			c = fgetc(file_in);
		}
		name[i] = '\0';
		i = 0;
		c = fgetc(file_in);
		while (c == ' ') { c = fgetc(file_in); }
		for (; i < 3; i++) {
			for (int j = 0; j < 3; j++){
				scores_s[i][j] = c;
				c = fgetc(file_in);
			}
			while (c == ' ') { c = fgetc(file_in); }
		}

		i = 0;
		for (; i < 3; i++) {
			scores[i] =(scores_s[i][0]-48)*100+ (scores_s[i][1] - 48) *10+ (scores_s[i][2] - 48);
		}
		sum = scores[0] + scores[1] + scores[2];
	}
	void output() {
		printf("IDcode:%s Name:%s Math:%d English:%d Chinese:%d the sum of scores:%d\n", IDcode, name, scores[0], scores[1], scores[2], sum);
	}
};

link_list *CreateList_Front();
link_list *CreateList_End();
void output_link_list(link_list *head,char*type);
int length(link_list*head);
link_list* delete_node(link_list* node, char deldata);
link_list* reverse(link_list*node);
link_list middle(link_list* node, link_list a_node);
link_list* Create_in_order(link_list *head, int number);
link_list *list_together(link_list*link1, link_list *link2);
link_list *get_list_in_order(link_list *head);
link_list last_4(link_list*head);

#endif // !__HOMEWORK_FUNCTIONS_LOADING_H__
