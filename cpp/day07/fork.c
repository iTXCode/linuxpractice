#include<stdio.h>
#include<unistd.h>


int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("father pid:%d,ppid=%d,pid=%d\n",getpid(),getppid(),pid);
  }else if(pid==0){
    printf("child pid:%d,ppid=%d,pid=%d\n",getpid(),getppid(),pid);
    sleep(3);
  }else{
    perror("fork");
    //perror用于读取创建进程的状态
  }
  return 0;
}
