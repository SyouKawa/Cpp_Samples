#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

void main() {

	//background();
	account *src_accounts = NULL;
	infor *src_infor = NULL;
	src_accounts=login_pre();
	src_infor = infor_pre();

	char search_name[USR_NAME_LEN];
	char search_ID[USR_ID_LEN];
	char change_ID[USR_ID_LEN];
	char search_acc[USR_NAME_LEN];
	char login_account[USR_NAME_LEN];
	char login_pwd[USR_PWD_LEN];
	int verify = 0;
		
		verify=login_UI(login_account, login_pwd, src_accounts);
		if (verify == -1) goto exit;
	int mode = 0;
	main:	
		if(mode!=3)system("cls");
		background(verify, 0,0,src_accounts, src_infor);

	
	int back = -1;
	while (1)
	{
	printf("\n\n\t\t\t\t请输入您所要的选项(或者输入-1回到上一目录，主目录无法返回)：");
	scanf("%d", &mode);
		switch (mode)
		{
		case 1:
mode1:		if (verify == 1) { system("cls"); background(verify, mode, 0, src_accounts, src_infor); }
			if (verify == 0) { system("cls"); background(verify, mode, 0, src_accounts, src_infor); }
			int choice = -1;
			printf("\n\n\t\t\t\t请输入您所要的选项(或者输入-1回到上一目录)：");
			scanf("%d", &choice);
			system("cls");
			if (verify == 1 && choice == 1)
				background(verify, mode, choice, src_accounts, src_infor);
			if (choice == 2) check_name_func(search_name, src_infor);
			if (choice == 3)info_check_ID_func(search_ID, src_infor);
			if (choice == 4) { system("cls"); background(verify, mode, choice, src_accounts, src_infor); }
			if (choice == -1) goto main;
			if (choice == 9) goto exit;
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto mode1;
			if (back == 0) goto exit;
			break;
		
		case 2:
			src_infor=add_info(src_infor);
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;

		case 3:
			src_infor=change_info(change_ID, src_infor);
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;
		case 4:
			src_infor=delete_name_func(src_infor);
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;

		case 5:
			src_accounts=add_acc(src_accounts);
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;

		case 6:
			src_accounts=change_pwd(login_account, src_accounts);
			printf("\n\t\t在当前屏幕输入完成，直接输入-1，继续选择其他选项：");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;
		case 7:
			src_accounts=delete_acc(src_accounts);
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;
		case 8:
			if (verify == 1) { system("cls"); background(verify, mode, 0, src_accounts, src_infor); }
			printf("\n\t\t是否回到上一界面(1:回到上一界面/0：直接退出)？");
			scanf("%d", &back);
			if (back == 1) goto main;
			if (back == 0) goto exit;
			break;
		case 9: goto exit;
		}
		//if (verify == 0)background(verify, mode,0,src_accounts, src_infor);
		//if(verify==1)background(verify, mode,0,src_accounts, src_infor);
		goto main;
	}
exit:	

	FILE *outfile = fopen("usr_infor.txt", "r+");
	for (; src_infor != NULL; src_infor = src_infor->next) {
		fseek(outfile, 0, SEEK_CUR);
		fprintf(outfile, "%s %s %d %d %d", src_infor->usr_id, src_infor->usr_name, src_infor->score[0], src_infor->score[1], src_infor->score[2]);
		fprintf(outfile, "\n");
	}
	FILE *outfile2 = fopen("usr_account.txt", "r+");
	for (; src_accounts != NULL; src_accounts = src_accounts->next) {
		fseek(outfile2, 0, SEEK_CUR);
		fprintf(outfile2, "%s %s %d", src_accounts->usr_name, src_accounts->usr_pwd, src_accounts->authority);
		fprintf(outfile2, "\n");
	}
	system("pause");
}

