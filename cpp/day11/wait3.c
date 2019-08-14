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
    printf("child1: %d\n",getpid());
    exit(0);
  }
   
  ret=fork();
  if(ret==0){
    printf("child2:%d\n",getpid());
    exit(0);
  }
  //父进程如果不关注子进程具体的退出状态
 printf("father : %d\n",getpid()) ;
 ret=wait(NULL);
 printf("wait1: %d\n",ret);
 ret=wait(NULL);
 printf("wait2: %d\n",ret);
 ret=wait(NULL);
 printf("wait3: %d\n",ret);  
  while(1){
    sleep(1);
  }
  return 0;
}
