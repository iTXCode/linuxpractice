#include<stdio.h>
#include<unistd.h>

int main(){

  printf("这一句printf只有父进程执行\n");
  pid_t ret=fork();
  printf("下面的代码父子进程都执行:\n");
  if(ret>0){
  printf("father pid:%d,ppid:%d\n",getpid(),getppid());
  }else if(ret==0){
    printf("son pid:%d,ppid:%d\n",getpid(),getppid());
  }else{
    perror("fork");
  }
  sleep(1);
  return 0;
}
