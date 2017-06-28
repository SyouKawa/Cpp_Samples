#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

#define N 10000000

void lock(int *lock){
	while(*lock==1);
	*lock=1;
}

void unlock(int *lock){
	*lock=0;
}


int main(int argc,char* argv[])
{
	int shmid;
	shmid=shmget(1000,4096,IPC_CREAT|0600);
	if(-1==shmid){
		perror("shmget");
		return -1;
	}

	int* p;
	p=(int*)shmat(shmid,NULL,0);
	if(p==(int*)-1){
		perror("shmat");
		return -1;
	}
	*p=0;
	int i;

	int flag=-1;
	if(!fork()){
		for(i=0;*p<2*N;i++){
			lock(&flag);
			if(flag==1&&*p<2*N) *p=*p+1;
			unlock(&flag);
		}
		exit(0);
	}
	else{
		for(i=0;*p<2*N;i++){	
			lock(&flag);
			if(flag==1&&*p<2*N) *p=*p+1;
			unlock(&flag);
		}
//		wait(NULL);
		printf("the value %d\n",*p);
		return 0;
	}
}
