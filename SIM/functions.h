#pragma once
#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_

#define USR_NAME_LEN 10
#define USR_PWD_LEN 18
#define USR_ID_LEN 13
typedef struct usr_account{
	
	char usr_name[USR_NAME_LEN];
	char usr_pwd[USR_PWD_LEN];
	short authority;
	struct usr_account * next;

}account;

typedef struct usr_infor
{
	char usr_id[USR_ID_LEN];
	char usr_name[USR_NAME_LEN];
	int score[3];
	struct usr_infor *next;
}infor;

//UI
void background(int verify,int mode,int choice,account *accounts,infor *infors);

//Ԥ����
account *login_pre();
infor *infor_pre();

//��������
void print_infor(infor*infors);
void print_acc(account*accounts);
void std_input(char*receive, size_t size, short mode);

//��¼���
int login_UI(char *login_account, char *login_pwd,account *accounts);
account *check_acc(char*acc, account *accounts);
void check_ID_func(char*check_ID, infor*infors);

//ѧ����Ϣ����ɾ���
infor *add_info(infor *infors);
infor* delete_name_func(infor *infors);
int info_check_ID_func(char*check_ID, infor*infors);
void check_name_func(char*check_name, infor*infors);
infor* change_info(char*change_infor, infor *infors);

//��¼�û�����ɾ���
account* add_acc(account *accounts);
account *delete_acc(account *accounts);
void check_acc_func(char*search_acc, account*accounts);
account *change_name(char*login_account, account *accounts);
account* change_pwd(char*login_account, account *accounts);

#endif // !__FUNCTIONS_H_
