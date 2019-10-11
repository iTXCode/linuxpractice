#include<stdio.h>
#include<unistd.h>

int main(){
  pid_t pid= fork();
  if(pid>0){
    int count=5;
    while(count>0){
      printf("father:%d\n",getpid());
      sleep(1);
      count--;
    }
    }else if(pid==0){
      while(1){
        printf("child:%d,ppid=%d\n",getpid(),getppid());
        sleep(1);
      }
  }else{
    perror("fork");
  }
  return 0;
}
