#include<stdio.h>
#include<unistd.h>
int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("father:%d,ppid:%d\n",getpid(),getppid());
    while(1){
      sleep(1);
    }
  }else if(pid==0){
    printf("child:%d,ppid:%d\n",getpid(),getppid());
    while(1){
      sleep(1);
    }
  }else{
    perror("fork");
  }
  return 0;
}
