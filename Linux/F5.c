#include <stdio.h>
#include <unistd.h>

  void failure(void){
          printf("hello world");
          close(STDOUT_FILENO);
  }
//什么都不输出

 void success(void){
         printf("hello world\n");
         close(STDOUT_FILENO);
 }
//hello world

 int main(){
    failure();
    success();

    return 0;
 }