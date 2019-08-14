#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  pid_t ret=fork();
  if(ret==0){
    printf("child1 %d\n",getpid());
    exit(0);
  }
  ret=fork();
  if(ret==0){
    printf("child2 %d\n",getpid());
    exit(0);
  }
  printf("father %d\n",getpid());
  //父进程如果不关注子进程具体的退出状态
  wait(NULL);
  wait(NULL);
  while(1){
    sleep(1);
  }
  return 0;
}
