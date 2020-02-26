#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){
  pid_t ret1=fork();

  if(ret1==0){
    printf("child1 pid:%d\n",getpid());
    sleep(3);
    exit(0);
  }

  pid_t ret2=fork();

  if(ret2==0){
    printf("child2 pid:%d\n",getpid());
    sleep(1);
    exit(0);
  }

  printf("father pid:%d\n",getpid());
  int ret=0;
  int count=0;
  while(1){
    ret=waitpid(-1,NULL,WNOHANG);
    //参数options 选择位WNOHANG，使得waitpid函数变成非阻塞函数
    printf("waitpid1 :%d\n",ret);

    if(ret>0){
      break;
    }
    count++;
  }

  printf("count=%d\n",count);

  ret=waitpid(ret2,NULL,0);
  printf("waitpid2 :%d\n",ret);
  return 0;
}
