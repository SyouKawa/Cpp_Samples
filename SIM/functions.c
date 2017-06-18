#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"


//Ԥ����
void help() {
	
}

void background(int verify,int mode,int choice,account *accounts,infor *infors) {
#define N 15
	char *logo[N]= { "��������������������     Students Information manage System-ѧ����Ϣ����ϵͳ ver 0.1","��������������������","��������������������","��������������������","��������������������","��������������������","��������������������",\
		"- - - - - - - - - ��","��������������������","��������������������","�������������������������� ^ -- ^","������������������������������v�㣩��","���������������������ߣߣ��ߤ� /����������/",\
		"������������������������������/�ߣߣߣߣ�/ ","�ߩߩߩߩߩߩߩߩߩ�" };
	char * admin_logo[N] = { "��������������������     Students Information manage System-ѧ����Ϣ����ϵͳ ver 0.1","��������������������  [1]����ѧ����Ϣ","��������������������  [2]���ѧ����Ϣ","��������������������  [3]���ѧ����Ϣ","��������������������  [4]ɾ��ѧ����Ϣ","��������������������  [5]��Ӳ�ѯ��¼�û�","��������������������  [6]�����ǰ�û���¼��Ϣ",\
		"- - - - - - - - - ��  [7]ɾ���û�","��������������������  [8]����ȫ���û�","��������������������  [9]�˳�","�������������������������� ^ -- ^","������������������������������v�㣩��","���������������������ߣߣ��ߤ� /����������/",\
		"������������������������������/�ߣߣߣߣ�/ ","�ߩߩߩߩߩߩߩߩߩ�" };
	
	//system("cls");


	//normal ���� 00
	for (int i = 0; verify==0&&mode == 0 && i < N; i++) {
		printf("%s", logo[i]);
		if (i == 2 && verify == 1) printf("  [2]������������");
		if (i == 3 && verify == 1)printf("  [3]����ѧ�ż���");
		if (i == 9 && verify)printf("  [9]�˳�");
		printf("\n");
	}
	
	//admin ����  10
	for (int i = 0; verify==1&&mode==0&&i < N; i++) {
		puts(admin_logo[i]);
	}

	//mode 1 ����
	for (int i = 0;choice==0&&mode==1&&i<N;i++) {
		printf("%s",logo[i]);
		if (i == 1 && verify == 1) printf("  [1]����ȫ��ѧ����Ϣ");
		if (i == 2 && verify == 1) printf("  [2]������������");
		if (i == 3 && verify == 1)printf("  [3]����ѧ�ż���");
		if (i == 4 && verify)printf("  [4]ѧ���춯����");
		printf("\n");
	}
	//mode 6 ����

	//admin ����ȫ��  mode=11   1 11
	for (int i = 0; verify==1 &&mode == 1 &&choice==1 && i < N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\tѧ��\t \t����   ��ѧ  ����  Ӣ��\n");
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

	//admin ����ѧ���춯 mode=14
	for (int i = 0; verify == 1 && mode == 1 && choice==4 && i<N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\tѧ��\t \t����   ��ѧ  ����  Ӣ��\n");
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

	//mode 8 ����ȫ���˻�
	for (int i = 0; verify == 1 && mode == 8 && i < N; i++) {
		if (i < 2) printf("%s", logo[i]);
		else if (i == 2) {
			printf("%s", logo[i]);
			printf("\t\t�˻�����\t  ����  Ȩ��\n");
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


//��������
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

	//�����߽�ļ��û��д��->OK��
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
				printf("\n��Ǹ���������볬���涨�ַ���Խ���ַ�������ʾ����ϵͳ���Զ�Ϊ��ɾ�������ַ���\n\t\t�����˶���Ҫ�������Ϣ������¼�롣\n\t\t������������û����棬������������ɱ���Ϊ���û������������˶Ժ�����޸�ҳ����ġ�\n");
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



//��¼���
int login_UI(char *login_account,char *login_pwd,account*accounts) {
	//background();
	account *temp = NULL;
	memset(login_account, 0, USR_NAME_LEN);
	memset(login_pwd, 0, USR_PWD_LEN);
	
	for (int i = 0; i < 10; i++) {
		printf("\n");
	}
	printf("\t\t\t\t\t\tע�����\n");
	printf("\t\t\t\t--��ϵͳ�ڴ򿪲鿴���ļ��ᱣ������Ļ��--\n");
	printf("\t\t\t\t--�벻Ҫʹ���������뷨����������--\n");
	printf("\n");
	printf("\t\t\t\t\t\t�����������˺ţ�");
	std_input(login_account, USR_NAME_LEN, 0);
	temp = check_acc(login_account, accounts);
	if (temp== NULL) return -1;//������ע��ѡ����˳�ѡ���������
	
	printf("\n");
	printf("\t\t\t\t\t\t�������������룺");
	std_input(login_pwd, USR_PWD_LEN, 1);
	if (check_pwd(login_pwd, accounts) == -1) return -1;//������ע��ѡ����˳�ѡ���������

	printf("\n");

	if (temp->authority == 2) return 0;
	if (temp->authority == 1) return 1;
}

account *check_acc(char*acc,account *accounts) {
	while (accounts != NULL) {
		if (strcmp(acc, accounts->usr_name) == 0) return accounts;
		accounts = accounts->next;
	}
	printf("\n\t\t\t��δ�ҵ���������ĵ�¼�û���\n��˶������˺��û������������룬��ע�����û�����ѡ��exit�˳�ϵͳ����\n");
	accounts = NULL;
	return accounts;
}

int check_pwd(char*pwd, account *accounts) {
	while (accounts != NULL) {
		if (strcmp(pwd, accounts->usr_pwd) == 0) return 0;
		accounts = accounts->next;
	}
	printf("\n\t\t\t\t\t��������󣡡�\n����ϵ����Ա���¼����Ա�˻��������롣��ѡ��exit�˳�ϵͳ����\n");
	return -1;
	}


//ѧ����Ϣ����ɾ���
infor *add_info(infor *infors) {//�ǵò���
	system("cls");
	infor *new_info = (infor*)malloc(sizeof(infor));
	memset(new_info, 0, sizeof(infor));
	printf("\t\t����������Ҫ��ӵ�ѧ�ţ�ѧ�Ÿ�ʽ����ѧ���-��-��-�༶-���-�����춯������-����\n");
	printf("\t\t\t\t");
	std_input(new_info->usr_id, USR_ID_LEN, 0);
	printf("\n\t\t\t\t������Ҫ��ӵ�������");
	std_input(new_info->usr_name, USR_NAME_LEN, 0);
	printf("\n\t\t\t\t������Ҫ��ӵĳɼ��� ");
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
			printf("\t�벻Ҫ������ͬ��ѧ�ţ�����ѧ���춯��������������ѧ����Ϣ�����в鿴-ID_rules��");
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

infor* delete_name_func(infor *infors) {//�߼�OK
	system("cls");
	char del_name[USR_NAME_LEN];
	memset(del_name, 0, sizeof(USR_NAME_LEN));

	printf("��������Ҫɾ�����û�����");
	rewind(stdin);
	scanf("%s", del_name);
	//std_input(del_name, USR_NAME_LEN, 0);
	infor *head = infors;
	infor *Prev = NULL;
	infor *temp = infors;
	while (infors != NULL) {
		if (strcmp(infors->usr_name, del_name) == 0) {
			if (Prev == NULL) {//ɾ��head
				Prev = infors;
				infors = infors->next;
				free(Prev);
				Prev = NULL;
				printf("\n\t\t\t\t\tɾ���ɹ���");
				return infors;
			}
			else {
				Prev->next = infors->next;
				//free(temp);
				//temp = NULL;
				printf("\n\t\t\t\t\tɾ���ɹ���");
				return head;
			}
		}
		Prev = infors;
		infors = infors->next;
		temp = infors;
	}
	printf("δ�ҵ��û����������˶Ժ��ٴ����롣\n");
	return head;
	//loading.
}

int info_check_ID_func(char*search_ID, infor*infors) {
	printf("\n�����������ѯ��ѧ�ţ�");
	std_input(search_ID, USR_ID_LEN, 0);
	while (infors != NULL) {
		if (strcmp(search_ID, infors->usr_id) == 0) {
			printf("\n");
			print_infor(infors);
			return 0;
		}
		infors = infors->next;
	}
	if(infors == NULL) printf("\n\t\t��Ǹ��δ�ҵ�������������������˶���Ϣ���������룬����ע��Ϊ���û���");
	return -1;
}

void check_name_func(char*search_name,infor*infors) {
	printf("�����������ѯ��������");
	std_input(search_name, USR_NAME_LEN, 0);
	while (infors != NULL) {
		if (strcmp(search_name,infors->usr_name)==0) {
			printf("\n");
			print_infor(infors);
			return;
		}
		infors = infors->next;
	}
	if(infors==NULL)printf("\n\t\t��Ǹ��δ�ҵ�������������������˶���Ϣ���������룬����ע��Ϊ���û���");
	return -1;
}

infor* change_info(char*change_infor, infor *infors) {
	infor *pointer = infors;
	char *name_check_equal = (char*)malloc(sizeof(USR_NAME_LEN));
	memset(name_check_equal, 0, sizeof(USR_NAME_LEN));
	
	system("cls");
	printf("������ѧ����ԭѧ�ţ�");
	std_input(change_infor, USR_ID_LEN, 0);
	while (infors != NULL) {
		if (strcmp(change_infor, infors->usr_id) == 0){ 
			printf("\n�Ѽ�������ѧ�ţ���˶Ը�����Ϣ��\n");
			print_infor(infors);
			break;
	}
		infors = infors->next;
	}
	if (infors == NULL) printf("\n��Ǹ��δ��⵽�������ѧ�ţ���˶Ժ��ٽ��и��ġ���ע��Ϊ���û���");
	infors = pointer;
	while (infors != NULL) {
		if (strcmp(change_infor, infors->usr_id) == 0) {
			printf("\n\n\t\t\t\t\t||||ѧ��������Ϣ¼��||||\n");//�ǵ�д�����ر�����
			printf("�������������ѧ�ţ�ѧ���춯���Բ�����ѧ�ű������� ID_rules.txt �Ĺ��򣬻�����-ID_rulesֱ�Ӳ鿴����");
			std_input(infors->usr_id, USR_ID_LEN, 0);
			if (strcmp(infors->usr_id, "-ID_rules") == 0) {
				printf("\n\n\t\t\t����������䶯ѧ�ţ�");
				std_input(infors->usr_id, USR_ID_LEN, 0);
			}
			printf("\n\t\t\t���������������");
			std_input(name_check_equal, USR_NAME_LEN, 0);
			if (strcmp(name_check_equal, infors->usr_name) != 0) printf("\n\t\t��ѧ������������������벻Ҫ�������ѧ��������");
			
			printf("\n\t\t\t����������ı���ɼ�����δ�仯��������ԭ�ɼ�����");
			scanf("%d%d%d", infors->score, (infors->score) + 1, (infors->score) + 2);
			return pointer;
		}
		infors = infors->next;
	}
}



//��¼�û�����ɾ���

account* add_acc(account *accounts) {
	system("cls");
	account *new_acc = (account*)malloc(sizeof(account));
	memset(new_acc, 0, sizeof(account));

	//printf("\t\t\t\t\t\t   �û���   ���루6~18����  Ȩ��\n");
	printf("��������Ҫ������û�����");
	std_input(new_acc->usr_name, USR_NAME_LEN, 0);
	printf("\n��������û������룺");
	std_input(new_acc->usr_pwd, USR_PWD_LEN, 1);
	printf("\n��������û���Ȩ�ޣ�");
	scanf("%d", &(new_acc->authority));
	
	new_acc->next = accounts;
	accounts = new_acc;

	return accounts;

	while (accounts != NULL);//��������ȷ��š�
}

account* delete_acc(account *accounts) {//�߼�OK
	system("cls");
	char *del_acc[USR_NAME_LEN];

	printf("��������Ҫɾ�����û�����");
	std_input(del_acc, USR_NAME_LEN, 0);
	account *head = accounts;
	account *Prev = NULL;
	account *temp = accounts;
	while (accounts != NULL) {
		if (strcmp(accounts->usr_name, del_acc) == 0) {
			if (Prev == NULL) {//ɾ��head
				Prev = accounts;
				accounts = accounts->next;
				free(Prev);
				Prev = NULL;
				printf("\n\t\t\t\t\tɾ���ɹ���");
				return accounts;
			}
			else {
				Prev->next = accounts->next;
				free(temp);
				temp = NULL;
				printf("\n\t\t\t\t\tɾ���ɹ���");
				return head;
			}
		}
		Prev = accounts;
		accounts = accounts->next;
		temp = accounts;
	}
	printf("δ�ҵ��û����������˶Ժ��ٴ����롣\n");
	return head;
	//loading.
}

void check_acc_func(char*search_acc, account*accounts) {
	printf("�����������ѯ���û���");
	std_input(check_acc, USR_ID_LEN, 0);
	while (accounts != NULL) {
		if (strcmp(check_acc, accounts->usr_name) == 0) {
			print_acc(accounts);
		}
		accounts = accounts->next;
	}
}

account* change(account* change_acc,account* accounts){
	printf("\n��ѡ����Ҫ�޸ĵ�ѡ�\n1.�޸��û���\n2.�޸�����");
	switch (getchar())
	{
	case 1:change_name(change_acc,accounts); break;
	case 2:change_pwd(change_acc,accounts); break;
	default: printf("�޴�ѡ��˳���");break;
	}
}

account* change_pwd(char*login_account, account *accounts) {
	account *pointer = accounts;
	while (accounts != NULL) {
		if (strcmp(login_account, accounts->usr_name) == 0) {
			printf("�������µ����룺");
			std_input(accounts->usr_pwd, USR_PWD_LEN, 1);
			printf("�������µ�Ȩ�ޣ�");
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
			printf("�������µ��û�������ֹ��������");//�ǵ�д�����ر�����
			std_input(accounts->usr_name, USR_NAME_LEN, 0);
			return pointer;
		}
		accounts = accounts->next;
	}
}
