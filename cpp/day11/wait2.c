#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  pid_t ret=fork();
  if(ret<0){
    perror("fork");
    return 0;
  }
  if(ret==0){
    exit(0);
  }
  ret=fork();
  if(ret==0){
    exit(0);
  }
  //父进程如果不关注子进程具体的退出状态
  wait(NULL);
  while(1){
    sleep(1);
  }
  return 0;
}
