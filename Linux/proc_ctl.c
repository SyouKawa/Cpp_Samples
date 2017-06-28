#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	pid_t pid=0;
	pid=fork();

	if(!pid){
		printf("Child Process: pid:%d,pgid:%d,ppid:%d\n",getpid(),getpgid(0),getppid());
//		sleep(3);

		// independent process create
		setpgid(0,0);
		printf("I create an independent process.pid:%d,pgid:%d,ppid:%d\n",getpid(),getpgid(0),getppid());
		
		while(1);
		
		return 0;
	}
	else{
		printf("Parent Process: pid:%d,pgid:%d,ppid:%d\n",getpid(),getpgid(0),getppid());
		while(1);
		return 0;
	}

	return 0;
}
