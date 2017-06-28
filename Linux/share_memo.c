#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#define MIN_MEMO 4096

int main(){
	int shmid=shmget(IPC_PRIVATE,MIN_MEMO,IPC_CREAT|0600);
	if(-1==shmid){
		perror("shmid");
		return -1;
	}
	
	char *p_memo=(char *)shmat(shmid,NULL,0);
	
	if(!fork()){
		
		char *p_memo=(char *)shmat(shmid,NULL,0);
		if((char *)-1==p_memo){
			perror("shmat");
			return -1;
		}

		printf("%s",p_memo);
		exit(0);
		
	}
	else{
		
		char *p_memo=(char *)shmat(shmid,NULL,0);
		if((char*)-1==p_memo){
			perror("shmat");
			return -1;
		}
		
		bzero(p_memo,MIN_MEMO);
		memcpy(p_memo,"How are you.\n",15);
		wait(NULL);
		exit(0);
	}

	return 0;
}
