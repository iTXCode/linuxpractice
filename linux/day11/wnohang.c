#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  pid_t ret1=fork();
  if(ret1==0){
    printf("child1: %d\n",getpid());
    sleep(3);
    exit(0);
  }
   
  pid_t ret2=fork();
  if(ret2==0){
    printf("child2:%d\n",getpid());
    sleep(1);
    exit(0);
  }
  //父进程如果不关注子进程具体的退出状态
 printf("father : %d\n",getpid()) ;
 int ret=0;
 int count=0;
 while(1){
 ret=waitpid(-1,NULL,WNOHANG);
 //WNOHANG加上之后，waitpid就变成了非阻塞
 printf("waitpid1: %d\n",ret);
 if(ret>0){
   break;
 } 
 ++count;
 }
 printf("count=%d\n",count);
 ret=waitpid(ret2,NULL,0);
 printf("waitpid2: %d\n",ret);
  while(1){
    sleep(1);
  }
  return 0;
}
