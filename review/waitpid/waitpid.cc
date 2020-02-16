#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>


int main(){
  pid_t ret1=fork();

  if(ret1==0){
    printf("child1 ppid:%d pid:%d\n",getpid(),getppid());
    sleep(1);
    exit(0);
  }

  if(ret1<0){
    perror("fork");
    exit(1);
  }

  pid_t ret2=fork();

  if(ret2==0){
    printf("child2 ppid:%d pid:%d\n",getppid(),getpid());
    sleep(3);
    exit(0);
  }

  if(ret2<0){
    perror("fork");
    exit(1);
  }

  printf("father pid:%d\n",getpid());
  int ret=waitpid(ret1,NULL,0);
  printf("waitpid1:%d\n",ret);
  ret=waitpid(ret2,NULL,0);
  printf("waitpid2:%d\n",ret);
  return  0;
}

