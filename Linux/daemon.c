#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
	if(fork()){
		exit(0);
	}
	setsid();
	chdir("/");

	umask(0);
	int i=0;

	for(;i<3;i++){
		close(i);
	}

	while(1);
}
