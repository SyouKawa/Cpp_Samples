#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"


//预处理
void help() {
	
}

void background(int verify,int mode,int choice,account *accounts,infor *infors) {
#define N 15
	char *logo[N]= { "━━━━━━━━━┒     Students Information manage System-学生信息管理系统 ver 0.1","┓┏┓┏┓┏┓┏┓┃","┛┗┛┗┛┗┛┗┛┃","┓┏┓┏┓┏┓┏┓┃","┛┗┛┗┛┗┛┗┛┃","┓┏┓┏┓┏┓┏┓┃","┛┗┛┗┛┗┛┗┛┃",\
		"- - - - - - - - - ┃","┓┏┓┏┓┏┓┏┓┃","┛┗┛┗┛┗┛┗┛┃","┓┏┓┏┓┏┓┏┓┃　　　 ^ -- ^","┛┗┛┗┛┗┛┗┛┃　　（　°v°）　","┓┏┓┏┓┏┓┏┓┃＿＿（＿っ /￣￣￣￣￣/",\
		"┃┃┃┃┃┃┃┃┃┃　　　　＼/＿＿＿＿＿/ ","┻┻┻┻┻┻┻┻┻┻" };
	char * admin_logo[N] = { "━━━━━━━━━┒     Students Information manage System-学生信息管理系统 ver 0.1","┓┏┓┏┓┏┓┏┓┃  [1]检索学生信息","┛┗┛┗┛┗┛┗┛┃  [2]添加学生信息","┓┏┓┏┓┏┓┏┓┃  [3]变更学生信息","┛┗┛┗┛┗┛┗┛┃  [4]删除学生信息","┓┏┓┏┓┏┓┏┓┃  [5]添加查询登录用户","┛┗┛┗┛┗┛┗┛┃  [6]变更当前用户登录信息",\
		"- - - - - - - - - ┃  [7]删除用户","┓┏┓┏┓┏┓┏┓┃  [8]检索全部用户","┛┗┛┗┛┗┛┗┛┃  [9]退出","┓┏┓┏┓┏┓┏┓┃　　　 ^ -- ^","┛┗┛┗┛┗┛┗┛┃　　（　°v°）　","┓┏┓┏┓┏┓┏┓┃＿＿（＿っ /￣￣￣￣￣/",\
		"┃┃┃┃┃┃┃┃┃┃　　　　＼/＿＿＿＿＿/ ","┻┻┻┻┻┻┻┻┻┻" };
	
	//system("cls");


	//normal 界面 00
	for (int i = 0; verify==0&&mode == 0 && i < N; i++) {
		printf("%s", logo[i]);
		if (i == 2 && verify == 1) printf("  [2]依据姓名检索");
		if (i == 3 && verify == 1)printf("  [3]依据学号检索");
		if (i == 9 && verify)printf("  [9]退出");
		printf("\n");
	}
	
	//admin 界面  10
	for (int i = 0; verify==1&&mode==0&&i < N; i++) {
		puts(admin_logo[i]);
	}

	//mode 1 界面
	for (int i = 0;choice==0&&mode==1&&i<N;i++) {
		printf("%s",logo[i]);
		if (i == 1 && verify == 1) printf("  [1]检索全部学生信息");
		if (i == 2 && verify == 1) printf("  [2]依据姓名检索");
		if (i == 3 && verify == 1)printf("  [3]依据学号检索");
		if (i == 4 && verify)printf("  [4]学籍异动检索");
		printf("\n");
	}
	//mode 6 界面

	//admin 检索全部  mode=11   1 11
	for (int i = 0; verify==1 &&mode == 1 &&choice==1 && i < N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\t学号\t \t姓名   数学  语文  英语\n");
		}
		else if (i>2&&infors != NULL) {
			printf("%s", logo[i]);
			if(i!=7)printf("\t\t");
			if (i == 7)printf("\t    ");
			print_infor(infors);
			infors = infors->next;
		}
		else printf("%s", logo[i]);
		printf("\n");

	}

	//admin 检索学籍异动 mode=14
	for (int i = 0; verify == 1 && mode == 1 && choice==4 && i<N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\t学号\t \t姓名   数学  语文  英语\n");
		}
		else if (i>2 && infors != NULL) {
			printf("%s", logo[i]);
			if(*((infors->usr_id)+11)!='_') print_infor(infors);
			if (i != 7)printf("\t\t");
			if (i == 7)printf("\t    ");
			infors = infors->next;
		}
		else printf("%s", logo[i]);
		printf("\n");
	}

	//mode 8 检索全部账户
	for (int i = 0; verify == 1 && mode == 8 && i < N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\t账户名称\t  密码  权限\n");
		}
		else if (i>2 && accounts != NULL) {
			printf("%s", logo[i]);
			if (i != 7)printf("\t\t");
			if (i == 7)printf("\t    ");
			print_acc(accounts);
			accounts = accounts->next;
		}
		else printf("%s", logo[i]);
		printf("\n");

	}
}

account *login_pre() {
	FILE *init_data_file = fopen("usr_account.txt", "r");
	account *new_node = (account *)malloc(sizeof(account));
	account *head_acc = NULL;
	memset(new_node, 0, sizeof(account));

	while((fscanf(init_data_file, "%s  %s  %d",new_node->usr_name,\
											new_node->usr_pwd,\
											&(new_node->authority)))>0) {
		fseek(init_data_file, 0, SEEK_CUR);
		if (NULL == head_acc) {
			head_acc = new_node;
			head_acc->next = NULL;
		}
		else
		{
			new_node->next = head_acc;
			head_acc = new_node;
		}
		new_node = (account *)malloc(sizeof(account));
		memset(new_node, 0, sizeof(account));
	}
	fclose(init_data_file);
	return head_acc;
}

infor *infor_pre() {
	FILE *init_data_file = fopen("usr_infor.txt", "r");
	infor *new_node = (infor *)malloc(sizeof(infor));
	infor *head_infor = NULL;
	memset(new_node, 0, sizeof(infor));

	while ((fscanf(init_data_file, "%s  %s  %d%d%d", new_node->usr_id, \
		new_node->usr_name, \
		new_node->score,\
		new_node->score+1,\
		new_node->score+2))>0) {
		fseek(init_data_file, 0, SEEK_CUR);
		if (NULL == head_infor) {
			head_infor = new_node;
			head_infor-> next= NULL;
		}
		else
		{
			new_node->next = head_infor;
			head_infor = new_node;
		}
		new_node = (account *)malloc(sizeof(account));
		memset(new_node, 0, sizeof(account));
	}
	fclose(init_data_file);
	return head_infor;
}


//操作处理
void print_infor(infor*infors) {
	printf("%s      %s   %d   %d   %d\n", infors->usr_id, \
								infors->usr_name,\
								infors->score[0],\
								infors->score[1], \
								infors->score[2]);
}

void print_acc(account*accounts) {
	printf("%s    %s   \t%d\n", accounts->usr_name, \
								  accounts->usr_pwd, \
								  accounts->authority);
}

void std_input(char*receive,size_t size,int mode) {
	char c;
	int input_count = 0;
	memset(receive, 0, size);

	//超过边界的检测没有写。->OK了
	while (c=getch()) {
		if ('\r' == c) return 0;
		if ('\b' == c) {
			if (input_count > 0) { 
				printf("\b \b");
				if (input_count > 0) receive[input_count--] = '\0';
			}
		}
		if ('\b' != c) {
			if (input_count < size) {
				if (0 == mode) printf("%c", c);
				if (1 == mode) printf("*");
			receive[input_count++] = c;
			}
			else { 
				receive[size - 1] = '\0'; 
				printf("\n抱歉，您的输入超过规定字符（越界字符不予显示），系统已自动为您删除多余字符。\n\t\t请您核对需要输入的信息后，重新录入。\n\t\t若您处于添加用户界面，您已输入的依旧保存为新用户，但建议您核对后进入修改页面更改。\n");
				break;
			}
			if (strcmp(receive, "-ID_rules") == 0) {
				system("cls");
				FILE *rule = fopen("ID_rules.txt", "r");
				char c;
				while ((c = fgetc(rule))!= EOF) {
					printf("%c",c);
				}
				printf("\n\n");
			}
		}
	}
	return 0;
}

/*void re_login(size_t size) {
	for (int i = 0; i < size; i++)printf(" ");
	for (int i = 0; i < size; i++)printf("\b");
}*/



//登录检查
int login_UI(char *login_account,char *login_pwd,account*accounts) {
	//background();
	account *temp = NULL;
	memset(login_account, 0, USR_NAME_LEN);
	memset(login_pwd, 0, USR_PWD_LEN);
	
	for (int i = 0; i < 10; i++) {
		printf("\n");
	}
	printf("\t\t\t\t\t\t注意事项：\n");
	printf("\t\t\t\t--在系统内打开查看的文件会保留在屏幕上--\n");
	printf("\t\t\t\t--请不要使用中文输入法，进行输入--\n");
	printf("\n");
	printf("\t\t\t\t\t\t请输入您的账号：");
	std_input(login_account, USR_NAME_LEN, 0);
	temp = check_acc(login_account, accounts);
	if (temp== NULL) return -1;//这里是注册选择和退出选择函数的入口
	
	printf("\n");
	printf("\t\t\t\t\t\t请输入您的密码：");
	std_input(login_pwd, USR_PWD_LEN, 1);
	if (check_pwd(login_pwd, accounts) == -1) return -1;//这里是注册选择和退出选择函数的入口

	printf("\n");

	if (temp->authority == 2) return 0;
	if (temp->authority == 1) return 1;
}

account *check_acc(char*acc,account *accounts) {
	while (accounts != NULL) {
		if (strcmp(acc, accounts->usr_name) == 0) return accounts;
		accounts = accounts->next;
	}
	printf("\n\t\t\t→未找到您所输入的登录用户←\n请核对您的账号用户名后重新输入，或注册新用户。（选择exit退出系统）←\n");
	accounts = NULL;
	return accounts;
}

int check_pwd(char*pwd, account *accounts) {
	while (accounts != NULL) {
		if (strcmp(pwd, accounts->usr_pwd) == 0) return 0;
		accounts = accounts->next;
	}
	printf("\n\t\t\t\t\t→密码错误！←\n请联系管理员或登录管理员账户更改密码。（选择exit退出系统）←\n");
	return -1;
	}


//学生信息的增删查改
infor *add_info(infor *infors) {//记得查重
	system("cls");
	infor *new_info = (infor*)malloc(sizeof(infor));
	memset(new_info, 0, sizeof(infor));
	printf("\t\t↓请输入您要添加的学号（学号格式：入学年份-月-日-班级-编号-有无异动，不带-）↓\n");
	printf("\t\t\t\t");
	std_input(new_info->usr_id, USR_ID_LEN, 0);
	printf("\n\t\t\t\t请输入要添加的姓名：");
	std_input(new_info->usr_name, USR_NAME_LEN, 0);
	printf("\n\t\t\t\t请输入要添加的成绩： ");
	scanf("%d%d%d", new_info->score, (new_info->score) + 1, (new_info->score) + 2);


	int cmp = 0;
	cmp = strcmp(new_info->usr_id, infors->usr_id);
	infor *Prev = NULL;
	infor *head = infors;
	while (infors != NULL) {
	cmp = strcmp(new_info->usr_id, infors->usr_id);
		if (cmp < 0) {
			if (Prev == NULL) {
				new_info->next = infors;
				infors = new_info;
				return infors;
			}
			else {
				Prev->next = new_info;
				new_info->next = infors;
				break;
			}
		}
		if (cmp == 0) {
			printf("\t请不要输入相同的学号，属于学籍异动的情况，请进入变更学生信息操作中查看-ID_rules。");
			return head;
		}
		if (cmp > 0) {
			Prev = infors;
			infors = infors->next;
		}
	}
	if (cmp > 0 && infors == NULL) {
		Prev->next = new_info;
		new_info->next = NULL;
	}
	infors = head;
	return head;
}

infor* delete_name_func(infor *infors) {//逻辑OK
	system("cls");
	char del_name[USR_NAME_LEN];
	memset(del_name, 0, sizeof(USR_NAME_LEN));

	printf("请输入您要删除的用户名：");
	rewind(stdin);
	scanf("%s", del_name);
	//std_input(del_name, USR_NAME_LEN, 0);
	infor *head = infors;
	infor *Prev = NULL;
	infor *temp = infors;
	while (infors != NULL) {
		if (strcmp(infors->usr_name, del_name) == 0) {
			if (Prev == NULL) {//删除head
				Prev = infors;
				infors = infors->next;
				free(Prev);
				Prev = NULL;
				printf("\n\t\t\t\t\t删除成功。");
				return infors;
			}
			else {
				Prev->next = infors->next;
				//free(temp);
				//temp = NULL;
				printf("\n\t\t\t\t\t删除成功。");
				return head;
			}
		}
		Prev = infors;
		infors = infors->next;
		temp = infors;
	}
	printf("未找到用户名，请您核对后，再次输入。\n");
	return head;
	//loading.
}

int info_check_ID_func(char*search_ID, infor*infors) {
	printf("\n请输入您想查询的学号：");
	std_input(search_ID, USR_ID_LEN, 0);
	while (infors != NULL) {
		if (strcmp(search_ID, infors->usr_id) == 0) {
			printf("\n");
			print_infor(infors);
			return 0;
		}
		infors = infors->next;
	}
	if(infors == NULL) printf("\n\t\t抱歉，未找到您输入的姓名，请您核对信息后重新输入，或将其注册为新用户。");
	return -1;
}

void check_name_func(char*search_name,infor*infors) {
	printf("请输入您想查询的姓名：");
	std_input(search_name, USR_NAME_LEN, 0);
	while (infors != NULL) {
		if (strcmp(search_name,infors->usr_name)==0) {
			printf("\n");
			print_infor(infors);
			return;
		}
		infors = infors->next;
	}
	if(infors==NULL)printf("\n\t\t抱歉，未找到您输入的姓名，请您核对信息后重新输入，或将其注册为新用户。");
	return -1;
}

infor* change_info(char*change_infor, infor *infors) {
	infor *pointer = infors;
	char *name_check_equal = (char*)malloc(sizeof(USR_NAME_LEN));
	memset(name_check_equal, 0, sizeof(USR_NAME_LEN));
	
	system("cls");
	printf("请输入学生的原学号：");
	std_input(change_infor, USR_ID_LEN, 0);
	while (infors != NULL) {
		if (strcmp(change_infor, infors->usr_id) == 0){ 
			printf("\n已检索到本学号，请核对该生信息。\n");
			print_infor(infors);
			break;
	}
		infors = infors->next;
	}
	if (infors == NULL) printf("\n抱歉，未检测到您输入的学号，请核对后再进行更改。或注册为新用户。");
	infors = pointer;
	while (infors != NULL) {
		if (strcmp(change_infor, infors->usr_id) == 0) {
			printf("\n\n\t\t\t\t\t||||学生的新信息录入||||\n");//记得写个查重报错函数
			printf("请输入该生的新学号（学籍异动可以产生的学号变更请参照 ID_rules.txt 的规则，或输入-ID_rules直接查看）：");
			std_input(infors->usr_id, USR_ID_LEN, 0);
			if (strcmp(infors->usr_id, "-ID_rules") == 0) {
				printf("\n\n\t\t\t请输入该生变动学号：");
				std_input(infors->usr_id, USR_ID_LEN, 0);
			}
			printf("\n\t\t\t请输入该生姓名：");
			std_input(name_check_equal, USR_NAME_LEN, 0);
			if (strcmp(name_check_equal, infors->usr_name) != 0) printf("\n\t\t该学号与该生姓名不符，请不要随意更改学生姓名。");
			
			printf("\n\t\t\t请输入该生的变更成绩（如未变化，请输入原成绩）：");
			scanf("%d%d%d", infors->score, (infors->score) + 1, (infors->score) + 2);
			return pointer;
		}
		infors = infors->next;
	}
}



//登录用户的增删查改

account* add_acc(account *accounts) {
	system("cls");
	account *new_acc = (account*)malloc(sizeof(account));
	memset(new_acc, 0, sizeof(account));

	//printf("\t\t\t\t\t\t   用户名   密码（6~18个）  权限\n");
	printf("请输入您要加入的用户名：");
	std_input(new_acc->usr_name, USR_NAME_LEN, 0);
	printf("\n请输入该用户的密码：");
	std_input(new_acc->usr_pwd, USR_PWD_LEN, 1);
	printf("\n请输入该用户的权限：");
	scanf("%d", &(new_acc->authority));
	
	new_acc->next = accounts;
	accounts = new_acc;

	return accounts;

	while (accounts != NULL);//有序插入先放着。
}

account* delete_acc(account *accounts) {//逻辑OK
	system("cls");
	char *del_acc[USR_NAME_LEN];

	printf("请输入您要删除的用户名：");
	std_input(del_acc, USR_NAME_LEN, 0);
	account *head = accounts;
	account *Prev = NULL;
	account *temp = accounts;
	while (accounts != NULL) {
		if (strcmp(accounts->usr_name, del_acc) == 0) {
			if (Prev == NULL) {//删除head
				Prev = accounts;
				accounts = accounts->next;
				free(Prev);
				Prev = NULL;
				printf("\n\t\t\t\t\t删除成功。");
				return accounts;
			}
			else {
				Prev->next = accounts->next;
				free(temp);
				temp = NULL;
				printf("\n\t\t\t\t\t删除成功。");
				return head;
			}
		}
		Prev = accounts;
		accounts = accounts->next;
		temp = accounts;
	}
	printf("未找到用户名，请您核对后，再次输入。\n");
	return head;
	//loading.
}

void check_acc_func(char*search_acc, account*accounts) {
	printf("请输入您想查询的用户：");
	std_input(check_acc, USR_ID_LEN, 0);
	while (accounts != NULL) {
		if (strcmp(check_acc, accounts->usr_name) == 0) {
			print_acc(accounts);
		}
		accounts = accounts->next;
	}
}

account* change(account* change_acc,account* accounts){
	printf("\n请选择您要修改的选项：\n1.修改用户名\n2.修改密码");
	switch (getchar())
	{
	case 1:change_name(change_acc,accounts); break;
	case 2:change_pwd(change_acc,accounts); break;
	default: printf("无此选项，退出。");break;
	}
}

account* change_pwd(char*login_account, account *accounts) {
	account *pointer = accounts;
	while (accounts != NULL) {
		if (strcmp(login_account, accounts->usr_name) == 0) {
			printf("请输入新的密码：");
			std_input(accounts->usr_pwd, USR_PWD_LEN, 1);
			printf("请输入新的权限：");
			scanf("%d", &(accounts->authority));
			return pointer;
		}
		accounts = accounts->next;
	}
}

account* change_name(char*login_account,account *accounts) {
	account *pointer = accounts;
	while (accounts != NULL) {
		if (strcmp(login_account, accounts->usr_name) == 0) {
			printf("请输入新的用户名（禁止重名）：");//记得写个查重报错函数
			std_input(accounts->usr_name, USR_NAME_LEN, 0);
			return pointer;
		}
		accounts = accounts->next;
	}
}
