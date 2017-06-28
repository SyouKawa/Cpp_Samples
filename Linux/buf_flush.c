#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
	printf("Hello \n");//
	fork();
	printf("world.\n");

	return 0;
}
