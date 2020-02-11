#include<stdio.h>
#include<unistd.h>

/*
 *该程序用于验证僵尸进程的产生
 */ 

int main(){
  pid_t ret=fork();
  if(ret>0){
    printf("I'm father, pid:%d ppid:%d\n",getpid(),getppid());
    while(1){
      sleep(1);
    }
  }else if(ret==0){
    printf("I'm child,pid:%d ppid:%d\n",getpid(),getppid());
    int count =3;
    while(count>0){
      sleep(1);
      count--;
    }
  }else{
    perror("fork");
  }
  return 0;
}
