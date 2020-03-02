#include<stdio.h>
#include<sys/wait.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void MyHandler(int sig){
  (void) sig;
  printf("child exit!\n");

  while(1){
    //如果 ret >0 已经回收到一个进程,返回值就是子进程的pid
    //如果ret==0 还有子进程在,但是子进程没有结束
    //如果 ret<0 没有子进程了
    int ret=waitpid(-1,NULL,WNOHANG);
    if(ret>0){
      //这就继续执行循环
    }else{
      //退出循环
      break;
    }
  }
}

int main(){
  signal(SIGCHLD,MyHandler);

  for(int i=0;i<20;i++){
    pid_t ret=fork();
    if(ret>0){
      while(1){
        sleep(1);
      }
    }else if(ret==0){
      printf("child:%d\n",getpid());
      exit(0);
    }else {
      perror("fork");
    }
  }

  while(1){
    sleep(1);
  }
  return 0;
}
